#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
    float x, y, z;
    Vertex(float x, float y, float z)
        : x(x), y(y), z(z) {}

    Vertex(const Vertex& other)
        : x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Copied!" << std::endl;
    }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

void Function(const std::vector<Vertex>& vertices)
{
    for (int i = 0; i < vertices.size(); i++)
    {
        std::cout << vertices[i] << std::endl;
    }
} 

int main()
{
    std::vector<Vertex> vertices; // if using vertices(3), it will construct 3 objects
    // optimize the memory allocation
    vertices.reserve(3); // not construct the object, just reserve the memory allocation
    // if not reserve, it will resize the memory allocation for each element
    // vertices.push_back(Vertex(1, 2, 3)); // it resize for another element and copy the first element to the new one
    // vertices.push_back(Vertex(4, 5, 6)); // construct Vertex using push_back it copy into actual vector
    vertices.emplace_back(1, 2, 3);
    vertices.emplace_back(7, 8, 9); // construct Vertex using emplace_back it construct in place
    vertices.emplace_back(4, 5, 6);
    // vertices.push_back(Vertex(7, 8, 9));
    // vertices.push_back({4, 5, 6});
    // vertices.push_back({7, 8, 9});

    // for (int i = 0; i < vertices.size(); i++)
    // {
    //     std::cout << vertices[i] << std::endl;
    // }
    
    // vertices.erase(vertices.begin() + 1);

    // for (Vertex& v : vertices)
    // {
    //     std::cout << v << std::endl;
    // }


    return 0;
}