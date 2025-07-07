#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

class Fraction
{
    int n, d;

    void normalise()
    {
        if (d == 0)
            throw runtime_error("Denominator 0");
        if (d < 0)
        {
            n = -n;
            d = -d;
        }
        int g = gcd(abs(n), d);
        n /= g;
        d /= g;
    }

public:
    Fraction(int a, int b) : n(a), d(b) { normalise(); }
    Fraction(int a) : n(a), d(1) {}

    Fraction &operator*=(const Fraction &rhs)
    {
        n *= rhs.n;
        d *= rhs.d;
        normalise();
        return *this;
    }

    friend Fraction operator*(Fraction lhs, const Fraction &rhs);

    friend ostream &operator<<(ostream &os, const Fraction &f)
    {
        return os << f.n << '/' << f.d;
    }
};
Fraction operator*(Fraction lhs, const Fraction &rhs)
{
    lhs *= rhs;
    return lhs;
}
int main()
{
    Fraction f1(3, 8);
    Fraction f2 = 2 * f1;
    Fraction f3 = f1 * f2;
    Fraction f4 = f3;
    f4 *= f4;

    cout << f1 << '\n'
         << f2 << '\n'
         << f3 << '\n'
         << f4;
}
