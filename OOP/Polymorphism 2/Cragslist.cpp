#include <bits/stdc++.h>
#include "json.hpp"
using namespace std;
using json::JSON;

class TransactionInfo {
public:
    double required_money_amount;
    string name;
    string address;
    string id;
    string expire_date;
    int ccv;
};

class IPaymentAPI {
public:
    virtual void SetUserInfo(string name, string address) = 0;
    virtual void SetCardInfo(string id, string expire_date, int ccv) = 0;
    virtual bool MakePayment(double money) = 0;
    virtual ~IPaymentAPI() {}
};

class PayPalCreditCard {
public:
    string name;
    string address;
    string id;
    string expire_date;
    int ccv;
};

class PayPalOnlinePaymentAPI {
public:
    void SetCardInfo(const PayPalCreditCard* const card) {}
    bool MakePayment(double money) { return true; }
};

class PayPalPayment : public IPaymentAPI {
    PayPalOnlinePaymentAPI paypal;
    PayPalCreditCard card;
public:
    void SetUserInfo(string name, string address) {
        card.name = name;
        card.address = address;
    }
    void SetCardInfo(string id, string expire_date, int ccv) {
        card.id = id;
        card.expire_date = expire_date;
        card.ccv = ccv;
    }
    bool MakePayment(double money) {
        paypal.SetCardInfo(&card);
        return paypal.MakePayment(money);
    }
};

class StripeUserInfo {
public:
    string name;
    string address;
};

class StripeCardInfo {
public:
    string id;
    string expire_date;
};

class StripePaymentAPI {
public:
    static bool WithDrawMoney(StripeUserInfo user, StripeCardInfo card, double money) {
        return true;
    }
};

class StripePayment : public IPaymentAPI {
    StripeCardInfo card;
    StripeUserInfo user;
public:
    void SetUserInfo(string name, string address) {
        user.name = name;
        user.address = address;
    }
    void SetCardInfo(string id, string expire_date, int ccv) {
        card.id = id;
        card.expire_date = expire_date;
    }
    bool MakePayment(double money) {
        return StripePaymentAPI::WithDrawMoney(user, card, money);
    }
};

class SquareUserInfo {
public:
    string name;
    string address;
};

class SquareCardInfo {
public:
    string id;
    string expire_date;
    int ccv;
};

class SquarePaymentAPI {
public:
    static bool WithDrawMoney(string JsonQuery) {
        try {
            JSON obj = JSON::Load(JsonQuery);
            JSON user_info = obj["user_info"];
            string name = user_info[0].ToString();
            string address = user_info[1].ToString();
            double money = obj["money"].ToFloat();
            JSON card_info = obj["card_info"];
            string id = card_info["ID"].ToString();
            string expire_date = card_info["DATE"].ToString();
            int ccv = card_info["CCV"].ToInt();
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Amount: " << money << endl;
            cout << "Card ID: " << id << endl;
            cout << "Expiry: " << expire_date << endl;
            cout << "CCV: " << ccv << endl;
            return true;
        } catch (...) {
            cerr << "Error processing JSON payment request\n";
            return false;
        }
    }
};

class SquarePayment : public IPaymentAPI {
    SquareCardInfo card;
    SquareUserInfo user;
public:
    void SetUserInfo(string name, string address) {
        user.name = name;
        user.address = address;
    }
    void SetCardInfo(string id, string expire_date, int ccv) {
        card.id = id;
        card.expire_date = expire_date;
        card.ccv = ccv;
    }
    bool MakePayment(double money) {
        JSON request;
        request["user_info"] = json::Array(user.name, user.address);
        request["card_info"]["ID"] = card.id;
        request["card_info"]["DATE"] = card.expire_date;
        request["card_info"]["CCV"] = card.ccv;
        request["money"] = money;
        ostringstream oss;
        oss << request;
        string json_query = oss.str();
        return SquarePaymentAPI::WithDrawMoney(json_query);
    }
};

class Factory {
public:
    static IPaymentAPI* GetPaymentHelper() {
        return new SquarePayment();
    }
};

class Craigslist {
    IPaymentAPI* payment;
public:
    Craigslist() {
        payment = Factory::GetPaymentHelper();
    }
    bool Pay(TransactionInfo info) {
        payment->SetUserInfo(info.name, info.address);
        payment->SetCardInfo(info.id, info.expire_date, info.ccv);
        return payment->MakePayment(info.required_money_amount);
    }
};

int main() {
    TransactionInfo info = {20.5, "mostafa", "canada", "11-22-33-44", "09-2021", 333};
    Craigslist site;
    site.Pay(info);
    return 0;
}
