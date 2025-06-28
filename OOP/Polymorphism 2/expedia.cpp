#include <iostream>
#include <vector>
using namespace std;

class Reservable {
public:
    virtual double GetTotalCost() const = 0;
    virtual Reservable* Clone() const = 0;
    virtual ~Reservable() {}
};

class Flight : public Reservable {
private:
    double price_per_flight;
    int total_flights;

public:
    Flight(double price, int flights)
        : price_per_flight(price), total_flights(flights) {}

    Flight* Clone() const override {
        return new Flight(*this);
    }

    double GetTotalCost() const override {
        return price_per_flight * total_flights;
    }
};

class Hotel : public Reservable {
private:
    double price_per_night;
    int total_nights;

public:
    Hotel(double price, int nights)
        : price_per_night(price), total_nights(nights) {}

    Hotel* Clone() const override {
        return new Hotel(*this);
    }

    double GetTotalCost() const override {
        return price_per_night * total_nights;
    }
};

class Itinerary : public Reservable {
private:
    vector<Reservable*> reservations;

public:
    Itinerary() {}

    Itinerary(const Itinerary& other) {
        for (const Reservable* reservation : other.reservations) {
            reservations.push_back(reservation->Clone());
        }
    }

    ~Itinerary() {
        Clear();
    }

    void AddReservation(const Reservable& reservation) {
        reservations.push_back(reservation.Clone());
    }

    double GetTotalReservationCost() const {
        double total = 0;
        for (const Reservable* r : reservations)
            total += r->GetTotalCost();
        return total;
    }

    const vector<Reservable*>& GetReservations() const {
        return reservations;
    }

    void Clear() {
        for (const Reservable* reservation : reservations) {
            delete reservation;
        }
        reservations.clear();
    }

    Reservable* Clone() const override {
        return new Itinerary(*this);
    }

    double GetTotalCost() const override {
        return GetTotalReservationCost();
    }
};

class User {
private:
    vector<Itinerary*> itineraries;

public:
    ~User() {
        for (Itinerary* i : itineraries)
            delete i;
    }

    void AddItinerary(Itinerary* i) {
        itineraries.push_back(i);
    }

    double GetTotalCost() const {
        double total = 0;
        for (const Itinerary* i : itineraries)
            total += i->GetTotalReservationCost();
        return total;
    }
};

class Expedia {
private:
    User current_user;

public:
    void Run() {
        Itinerary* itinerary1 = new Itinerary();
        itinerary1->AddReservation(Flight(200.0, 2));
        itinerary1->AddReservation(Hotel(100.0, 3));

        current_user.AddItinerary(itinerary1);

        cout << "Total cost for user: $" << current_user.GetTotalCost() << endl;
    }
};

int main() {
    Expedia expediaApp;
    expediaApp.Run();
    return 0;
}
