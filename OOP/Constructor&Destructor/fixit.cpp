class OurPrice {
private:
    int _price; // Use a consistent naming convention

public:
    // Constructor
    OurPrice(int price) : _price(price) {}

    // Getter
    int GetPrice() {
        return _price;
    }

    // Setter with validation
    void SetPrice(int price) {
        const int MIN_PRICE = 10; // Avoid magic numbers
        this->_price = (price < MIN_PRICE) ? 0 : price;
    }

    // Method demonstrating usage of variables
    int SomeFun() {
        int price = 10; // Local variable
        int price2 = 20;
        int price3 = 20;

        return price + price2 + price3 + _price; // Clear distinction between local and member variables
    }
};
