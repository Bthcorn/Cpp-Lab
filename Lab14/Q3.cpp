#include <iostream>
#include <cmath>
#include <string>

class Point 
{
private:
    double x, y;
public:
    Point(double x, double y) : x(x), y(y) {}
    double getX() const { return x; }
    double getY() const { return y; }

    friend std::ostream &operator<<(std::ostream &os, const Point &p);
    friend std::istream &operator>>(std::istream &is, Point &p);
};



std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "(" << p.getX() << ", " << p.getY() << ")";
    return os;
}

std::istream &operator>>(std::istream &is, Point &p)
{
    double x, y;
    is >> x >> y;
    if (is.fail())
    {
        is.setstate(std::ios::failbit);
        return is;
    } else {
        p = Point(x, y);
    }
    return is;
}

int main()
{
    std::cout << "Enter a point: ";
    Point p(0, 0);

    if (!(std::cin >> p))
    {
        std::cout << "Invalid input." << std::endl;
        return 1;
    } else {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "The point is: " << p << std::endl;
    }
    return 0;
}
