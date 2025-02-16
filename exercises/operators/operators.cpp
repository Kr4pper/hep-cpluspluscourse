#include <iomanip>
#include <iostream>
#include <numeric>

class Fraction {
public:
    Fraction() = delete;
    Fraction(int num)
        : m_num(num)
        , m_denom(1)
    {
    }
    Fraction(int num, int denom)
        : m_num(num)
        , m_denom(denom)
    {
        normalize();
    }

    Fraction& operator*=(int n)
    {
        m_num *= n;
        normalize();
        return *this;
    }
    Fraction& operator*=(Fraction const& other)
    {
        m_num *= other.m_num;
        m_denom *= other.m_denom;
        normalize();
        return *this;
    }
    friend Fraction operator*(Fraction f, int i) { return f *= i; }
    friend Fraction operator*(int i, Fraction const& f) { return f * i; }
    friend Fraction operator*(Fraction a, Fraction const& b) { return a *= b; }

    friend bool operator==(Fraction const& a, Fraction const& b)
    {
        return a.m_num == b.m_num && a.m_denom == b.m_denom;
    }
    friend bool operator!=(Fraction const& a, Fraction const& b) { return !(a == b); }

    friend bool operator<(Fraction const& a, Fraction const& b)
    {
        return a.m_num * b.m_denom < b.m_num * a.m_denom;
    }
    friend bool operator>(Fraction const& a, Fraction const& b) { return b < a; }
    friend bool operator<=(Fraction const& a, Fraction const& b) { return !(a > b); }
    friend bool operator>=(Fraction const& a, Fraction const& b) { return !(a < b); }

    friend std::ostream& operator<<(std::ostream& os, Fraction const& frac)
    {
        os << "[" << frac.m_num << "," << frac.m_denom << "]";
        return os;
    }

private:
    void normalize()
    {
        const int gcd = std::gcd(m_num, m_denom);
        m_num /= gcd;
        m_denom /= gcd;
    }

    unsigned int m_num, m_denom;
};

void printAndCheck(std::string const& what, Fraction const& result, Fraction const& expected)
{
    const bool passed = result == expected;
    std::cout << std::left << std::setw(40) << what << ": " << (passed ? "PASS" : "** FAIL **") << "    " << result << "\n";
}
void printAndCheck(std::string const& what, bool result, bool expected)
{
    const bool passed = result == expected;
    std::cout << std::left << std::setw(40) << what << ": " << (passed ? "PASS" : "** FAIL **") << "    " << result << "\n";
}

int main()
{
    const Fraction three { 3 };
    const Fraction athird { 1, 3 };

    std::cout << "Three: " << three << '\n';
    std::cout << "One third: " << athird << '\n';

    // multiply fraction with an int
    printAndCheck("One third times two", athird * 2, Fraction { 2, 3 });
    printAndCheck("Two times one third", 2 * athird, Fraction { 2, 3 });

    // multiply two fractions
    printAndCheck("Three times one third", three * athird, Fraction { 1, 1 });
    printAndCheck("Three times one third", 3 * athird, Fraction { 1, 1 });

    // multiply in place
    Fraction f = athird;
    f *= 2;
    printAndCheck("One third times two", f, Fraction { 2, 3 });

    f *= athird;
    printAndCheck("Two third times one third", f, Fraction { 2, 9 });

    std::cout << std::boolalpha; // print bools as 'true' or 'false' from now on

    // more equality comparisons
    printAndCheck("One third == one third", (athird == Fraction { 1, 3 }), true);
    printAndCheck("One third != one forth", (athird != Fraction { 1, 4 }), true);
    printAndCheck("One third == two sixth", (athird == Fraction { 2, 6 }), true);
    printAndCheck("One third != three sixth", (athird != Fraction { 3, 6 }), true);

    // more comparisons
    const Fraction afourth { 1, 4 };
    printAndCheck("athird < athird", (athird < athird), false);
    printAndCheck("afourth < athird", (afourth < athird), true);
    printAndCheck("athird  <= athird", (athird <= athird), true);
    printAndCheck("athird  <= afourth", (athird <= afourth), false);
    printAndCheck("athird  > athird", (athird > athird), false);
    printAndCheck("afourth > athird", (afourth > athird), false);
    printAndCheck("athird >= athird", (athird >= athird), true);
    printAndCheck("athird >= afourth", (athird >= afourth), true);
}
