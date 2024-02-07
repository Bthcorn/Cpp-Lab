#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct Term
{
    int coeff;
    int exp;
};

class Polynomial
{
private:
    std::vector<Term> exps;

public:
    Polynomial()
    {
        exps = {};
        // std::cout << "Polynomial object created" << std::endl;
    }
    ~Polynomial()
    {
        exps.clear();
        // std::cout << "Polynomial object destroyed" << std::endl;
    }

    void setExps(int coeff, int exp)
    {
        Term t;
        t.coeff = coeff;
        t.exp = exp;
        exps.push_back(t);
    }

    Polynomial operator+(const Polynomial &other) const
    {
        Polynomial result;
        for (auto &t : exps)
        {
            result.setExps(t.coeff, t.exp);
        }
        for (auto &t : other.exps)
        {
            auto it = find_if(result.exps.begin(), result.exps.end(), [&](const Term &a) {
                return a.exp == t.exp;
            });
            if (it != result.exps.end())
            {
                it->coeff += t.coeff;
            }
            else
            {
                result.setExps(t.coeff, t.exp);
            }
        }

        std::sort(result.exps.begin(), result.exps.end(), [](const Term &a, const Term &b) {
            return a.exp > b.exp;
        });
        return result;
    }

    Polynomial operator-(const Polynomial &other) const
    {
        Polynomial result;
        for (auto &t : exps)
        {
            result.setExps(t.coeff, t.exp);
        }
        for (auto &t : other.exps)
        {
            auto it = find_if(result.exps.begin(), result.exps.end(), [&](const Term &a) {
                return a.exp == t.exp;
            });
            if (it != result.exps.end())
            {
                it->coeff -= t.coeff;
            }
            else
            {
                result.setExps(-t.coeff, t.exp);
            }
        }

        std::sort(result.exps.begin(), result.exps.end(), [](const Term &a, const Term &b) {
            return a.exp > b.exp;
        });


        return result;
    }

    Polynomial operator*(const Polynomial &other) const
    {
        Polynomial result;
        for (auto &t1 : exps)
        {
            for (auto &t2 : other.exps)
            {
                auto it = std::find_if(result.exps.begin(), result.exps.end(), [&](const Term &a) {
                    return a.exp == t1.exp + t2.exp;
                });
                if (it != result.exps.end())
                {
                    it->coeff += t1.coeff * t2.coeff;
                }
                else
                {
                    Term t;
                    t.coeff = t1.coeff * t2.coeff;
                    t.exp = t1.exp + t2.exp;
                    result.exps.push_back(t);
                }
            }
        }

        std::sort(result.exps.begin(), result.exps.end(), [](const Term &a, const Term &b) {
            return a.exp > b.exp;
        });

        return result;
    }
    
    friend std::ostream &operator<<(std::ostream &os, const Polynomial &p)
    {
        for (auto &t : p.exps)
        {
            if (t.coeff > 0)
            {
                os << " +";
                os << t.coeff << "x^" << t.exp;
            }
            else
            {
                os << " ";
                os << t.coeff << "x^" << t.exp;
            }
        }
        return os;
    }
};

int main()
{
    Polynomial p1;
    p1.setExps(2, 3);
    p1.setExps(4, 1);

    Polynomial p2;
    p2.setExps(3, 2);
    p2.setExps(5, 1);

    Polynomial p3 = p1 + p2;
    Polynomial p4 = p1 - p2;
    Polynomial p5 = p1 * p2;

    std::cout << "p1 = " << p1 << std::endl;
    std::cout << "p2 = " << p2 << std::endl;
    std::cout << "p1 + p2 = " << p3 << std::endl;
    std::cout << "p1 - p2 = " << p4 << std::endl;
    std::cout << "p1 * p2 = " << p5 << std::endl;

    return 0;
}