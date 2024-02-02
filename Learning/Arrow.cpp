#include <iostream>
#include <string>
#include <cstddef>

class Entity
{
public:
    int x;
    void Print() const
    {
        std::cout << "Hello!" << std::endl;
    }
};

class ScopedPtr //smart pointer auto free memory
{
private:
    Entity* m_Obj;
public:
    ScopedPtr(Entity* entity)
        : m_Obj(entity)
    {
    }

    ~ScopedPtr()
    {
        delete m_Obj;
    }

    Entity* operator->()
    {
        return m_Obj;
    }

    const Entity* operator->() const
    {
        return m_Obj;
    }
};

struct Vector3
{
    float x, y, z;
};

int main()
{
    Entity e;
    e.Print();
    Entity* ptr = &e;
    // (*ptr).Print();
    ptr->Print();
    ptr->x = 2;
    
    const ScopedPtr entity = new Entity();
    entity->Print();
    // entity->x = 2;

    // ((Vector3*)nullptr)->x = 1; //error: dereferencing nullptr
    // int offset = (int)&((Vector3*)nullptr)->x; loss of precision
    int offset2 = offsetof(Vector3, y);
    std::cout << offset2 << std::endl;
     
}