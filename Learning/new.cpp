#include <iostream>
#include <string>

using namespace std;

class Entity
{
private:
    string m_Name;
public:
    Entity() : m_Name("Unknown") {}
    Entity(const string &name) : m_Name(name) {}
    const string &GetName() const { return m_Name; }
};

int main()
{
    int a = 2;
    int* b = new int[50];

    Entity* e = new Entity(); // call default constructor
    // Entity* e = (Entity*)malloc(sizeof(Entity)); // create a pointer to a block of memory
    delete e;
    delete[] b;
    return 0;
}