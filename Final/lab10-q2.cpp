#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Term
{
    int coef;
    int expo;
};

class Polynomial
{
private:
    std::vector<Term> poly;

public:
    Polynomial()
    {
        poly = {};
    }

    ~Polynomial()
    {
        poly.clear();
    }

    void setPoly(int coef, int expo)
    {
        Term new_poly;
        new_poly.coef = coef;
        new_poly.expo = expo;
        poly.push_back(new_poly);
    }

    Polynomial operator+(const Polynomial &other)
    {
        Polynomial new_Polynomial;
        for (auto &t : poly)
        {
            new_Polynomial.setPoly(t.coef, t.expo);
        }
        for (auto &t : other.poly)
        {
            auto it = std::find_if(new_Polynomial.poly.begin(), new_Polynomial.poly.end(), [&](const Term &a)
                                   { return a.expo == t.expo; });
            if (it != new_Polynomial.poly.end())
            {
                it->coef += t.coef;
            }
            else
            {
                new_Polynomial.setPoly(t.coef, t.expo);
            }
        }

        std::sort(new_Polynomial.poly.begin(), new_Polynomial.poly.end(), [](const Term &a, const Term &b)
                  { return a.expo > b.expo; });

        return new_Polynomial;
    }

    Polynomial operator-(const Polynomial &other)
    {
        Polynomial new_Polynomial;
        for (auto &t : poly)
        {
            new_Polynomial.setPoly(t.coef, t.expo);
        }

        for (auto &t : other.poly)
        {
            auto it = std::find_if(new_Polynomial.poly.begin(), new_Polynomial.poly.end(), [&](const Term &a)
                                   { return a.expo == t.expo; });
            if (it != new_Polynomial.poly.end())
            {
                it->coef -= t.coef;
            }
            else
            {
                new_Polynomial.setPoly(-t.coef, t.expo);
            }
        }
        std::sort(new_Polynomial.poly.begin(), new_Polynomial.poly.end(), [](const Term &a, const Term &b)
                  { return a.expo > b.expo; });
        return new_Polynomial;
    }

    Polynomial operator*(const Polynomial &other)
    {
        Polynomial new_Polynomial;
        for (auto &t1 : poly)
        {
            for (auto &t2 : other.poly)
            {
                auto it = std::find_if(new_Polynomial.poly.begin(), new_Polynomial.poly.end(), [&](const Term &a)
                                       { return a.expo == t1.expo + t2.expo; });
                if (it != new_Polynomial.poly.end())
                {
                    it->coef += t1.coef * t2.coef;
                }
                else
                {
                    Term new_term;
                    new_term.coef = t1.coef * t2.coef;
                    new_term.expo = t1.expo + t2.expo;
                    new_Polynomial.poly.push_back(new_term);
                    // new_Polynomial.setPoly(t1.coef * t2.coef, t1.expo + t2.expo);
                }
            }
        }

        std::sort(new_Polynomial.poly.begin(), new_Polynomial.poly.end(), [](const Term &a, const Term &b)
                  { return a.expo > b.expo; });
        return new_Polynomial;
    }

    friend std::ostream &operator<<(std::ostream &os, const Polynomial &poly)
    {
        for (auto &it : poly.poly)
        {
            if (it.coef > 0)
            {
                os << " +" << it.coef;
            }
            else
            {
                os << " " << it.coef;
            }
            os << "x^" << it.expo;
        }
        return os;
    }
};

// std::ostream operator<<(std::ostream &os, const Polynomial &poly) {
//     for (auto &it : poly.poly)
// }

int main()
{
    Polynomial p1;
    p1.setPoly(2, 3);
    p1.setPoly(4, 1);

    Polynomial p2;
    p2.setPoly(3, 2);
    p2.setPoly(5, 0);

    Polynomial p3 = p1 + p2;
    Polynomial p4 = p1 - p2;
    Polynomial p5 = p1 * p2;

    std::cout << "Polynomial p1: " << p1 << '\n';
    std::cout << "Polynomial p2: " << p2 << '\n';
    std::cout << "p1 + p2: " << p3 << '\n';
    std::cout << "p1 - p2: " << p4 << '\n';
    std::cout << "p1 * p2: " << p5 << '\n';

    return 0;
}
