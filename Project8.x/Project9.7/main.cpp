#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction(char i) = delete;
    explicit Fraction(int num = 0, int den = 1)
        : m_numerator(num), m_denominator(den)
    {
        assert(den != 0);
        cout << "Converting constructor called" << endl;
    }

    Fraction(const Fraction& fraction)
        : m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
    {
        cout << "copy constructor called" << endl;
    }

    friend std::ostream& operator << (std::ostream& asd, const Fraction& f)
    {
        asd << f.m_numerator << " / " << f.m_denominator;
        return asd;
    }
};

void doSomething(Fraction frac)
{
    cout << frac << endl;
}

int main()
{
    Fraction('c');

    return 0;
}