#include <iostream>
#include <map>
#include <cmath>

class Double
{
private:
    double val;
    static constexpr double EPS = 1e-9;   // comparison tolerance

public:
    explicit Double(double v) : val(v) {}

    /* --- strict‑weak ordering for std::map --- */
    bool operator<(const Double& other) const
    {
        return val < other.val - EPS;
    }

    /* --- remaining comparisons, expressed via < and == --- */
    bool operator==(const Double& other) const
    {
        return std::fabs(val - other.val) < EPS;
    }
    bool operator>(const Double& other)  const { return other < *this; }
    bool operator<=(const Double& other) const { return *this < other || *this == other; }
    bool operator>=(const Double& other) const { return other <= *this; }
};

/* --------------------------- test driver --------------------------- */
int main()
{
    double d1 = 1 + 3.0 / 7.0 - 1;   // 3/7 with round‑off
    double d2 = 3.0 / 7.0;

    std::cout.precision(17);
    std::cout << "Raw doubles:\n"
              << "d1 = " << d1 << "\n"
              << "d2 = " << d2 << "\n"
              << "(d1 == d2) : " << (d1 == d2) << "\n\n";

    Double cd1(d1), cd2(d2);

    std::cout << "Wrapped in Double:\n"
              << "(cd1 == cd2) : " << (cd1 == cd2) << "\n\n";

    std::map<Double, int> mp;
    mp[cd1] = 10;
    mp[cd2] = 20;          // overwrites because cd1 == cd2

    std::cout << "map size : " << mp.size() << '\n';   // prints 1
    return 0;
}
