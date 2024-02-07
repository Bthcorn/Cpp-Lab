#include <iostream>
// #include <string>

class Fraction
{
public:
    double num, den;
    Fraction(double n = 0.0, double d = 1.0)
        : num(n), den(d)
    {
        if (den == 0)
        {
            std::cout << "Error: Denominator cannot be zero" << std::endl;
            exit(1);
        }
    }

    // static int gcd(int a, int b)
    // {
    //     if (b == 0)
    //         return a;
    //     return gcd(b, a % b);
    // }

    // gcd with no recursion
    static int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    Fraction operator+(const Fraction &other) const
    {
        int new_num = num * other.den + other.num * den;
        int new_den = den * other.den;
        int common = gcd(new_num, new_den);
        return Fraction(new_num / common, new_den / common);
    }

    Fraction operator-(const Fraction &other) const
    {
        int new_num = num * other.den - other.num * den;
        int new_den = den * other.den;
        int common = gcd(new_num, new_den);
        return Fraction(new_num / common, new_den / common);
    }

    Fraction operator*(const Fraction &other) const
    {
        int new_num = num * other.num;
        int new_den = den * other.den;
        int common = gcd(new_num, new_den);
        return Fraction(new_num / common, new_den / common);
    }

    Fraction operator/(const Fraction &other) const
    {
        int new_num = num * other.den;
        int new_den = den * other.num;
        int common = gcd(new_num, new_den);
        return Fraction(new_num / common, new_den / common);
    }

    friend bool operator==(const Fraction &f1, const Fraction &f2)
    {
        bool result = (f1.num * f2.den == f2.num * f1.den);
        return result;
    }

    friend bool operator<(const Fraction &f1, const Fraction &f2)
    {
        bool result = (f1.num * f2.den < f2.num * f1.den);
        return result;
    }

    friend bool operator>(const Fraction &f1, const Fraction &f2)
    {
        bool result = (f1.num * f2.den > f2.num * f1.den);
        return result;
    }

    friend std::ostream &operator<<(std::ostream &stream, const Fraction &fraction);
    friend std::istream &operator>>(std::istream &stream, Fraction &fraction);
};

std::ostream &operator<<(std::ostream &stream, const Fraction &fraction)
{
    stream << fraction.num << "/" << fraction.den;
    return stream;
}

std::istream &operator>>(std::istream &stream, Fraction &fraction)
{
    stream >> fraction.num;
    stream.ignore(1, '/');
    stream >> fraction.den;
    return stream;
}

int main()
{
    Fraction f1, f2;
    std::cout << "Enter first fraction (foramt a/b): ";
    std::cin >> f1;
    std::cout << "Enter second fraction (foramt a/b): ";
    std::cin >> f2;

    std::cout << "f1 + f2 = " << f1 + f2 << std::endl;
    std::cout << "f1 - f2 = " << f1 - f2 << std::endl;
    std::cout << "f1 * f2 = " << f1 * f2 << std::endl;
    std::cout << "f1 / f2 = " << f1 / f2 << std::endl;

    if (f1 == f2)
        std::cout << "f1 == f2" << std::endl;
    else if (f1 < f2)
        std::cout << "f1 < f2" << std::endl;
    else if (f1 > f2)
        std::cout << "f1 > f2" << std::endl;
    return 0;
}