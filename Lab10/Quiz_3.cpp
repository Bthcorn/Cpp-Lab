#include <iostream>

class Vertex
{
public:
    double x, y, z;
    Vertex(double x = 0.0, double y = 0.0, double z = 0.0)
        : x(x), y(y), z(z) {}

    Vertex operator+(const Vertex& other) const
    {
        return Vertex(x + other.x, y + other.y, z + other.z);
    }

    friend std::ostream& operator<<(std::ostream& stream, const Vertex& vertex);
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << "["<<vertex.x << ", " << vertex.y << ", " << vertex.z << "]";
    return stream;
}

int main()
{
    Vertex c1(2, 3, 4);
    Vertex c2(6, 7, 8);
    Vertex c3 = c1 + c2;
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << "c3 = " << c3 << std::endl;

    return 0;
}