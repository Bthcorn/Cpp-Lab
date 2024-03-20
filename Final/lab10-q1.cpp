#include <iostream>
#include <string>

class Fraction {
public:
    int num;
    int den;
    Fraction(int n = 0, int d = 1) : num(n), den(d) {}

    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else if (a == 0) {
            return b; }
        return gcd(b, a % b);
    }

    Fraction operator+(const Fraction& other) const {
        int new_num = num * other.den + other.num * den;
        int new_den = den * other.den;
        int common = gcd(new_num, new_den);
        return Fraction(new_num / common, new_den / common);
    }

    Fraction operator-(const Fraction& other) const {
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

    friend bool operator<(Fraction& f1, Fraction& f2) {
        bool result = f1.num * f2.den < f2.num * f1.den ? true : false;
        return result;
    }

    friend bool operator==(Fraction& f1, Fraction& f2) {
        bool result = f1.num * f2.den == f2.num * f1.den ? true : false;
        return result;
    }

    friend bool operator>(Fraction& f1, Fraction& f2) {
        bool result = f1.num * f2.den < f2.num * f1.den ? true : false;
        return result;
    }

    

    friend std::ostream &operator<<(std::ostream& stream, const Fraction& fraction);
    friend std::istream &operator>>(std::istream& stream, Fraction& fraction);
};

std::ostream &operator<<(std::ostream& stream, const Fraction& fraction) {
    stream << fraction.num << "/" << fraction.den;
    return stream;
}

std::istream &operator>>(std::istream& stream, Fraction& fraction) {
    stream >> fraction.num;
    stream.ignore(1, '/');
    stream >> fraction.den;
    return stream;
}

int main() {
    Fraction f1;
    Fraction f2;

    std::cout << "Enter first fraction (format a/b): ";
    std::cin >> f1;
    std::cout << "Enter second fraction (format a/b): ";
    std::cin >> f2;

    std::cout << "f1 + f2 = " << (f1 + f2) << '\n';
    std::cout << "f1 - f2 = " << (f1 - f2) << '\n';
    std::cout << "f1 * f2 = " << (f1 * f2) << '\n';
    std::cout << "f1 / f2 = " << (f1 / f2) << '\n';

    if (f1 == f2) std::cout << "f1 is equal to f2" << '\n';
    if (f1 > f2) std::cout << "f1 is greater than f2" << '\n';
    if (f1 < f2) std::cout << "f1 is less than f2" << '\n';

}