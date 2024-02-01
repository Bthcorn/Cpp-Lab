#include <iostream>
#include <string>

class Entity 
{
public:
    Entity()
    {
        std::cout << "Created Entity!" << std::endl;
    }

    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }
};

int* CreateArray()
{
    int array[50]; //stack, will be destroyed after function call resulting failure
    // int* array = new int[50]; //heap, will not be destroyed after function call
    // or passing pointer or reference to array
    return array;
}

class ScopedPtr
{
private:
    Entity* m_Ptr; //pointer to Entity object on heap
public:
    ScopedPtr(Entity* ptr)
        : m_Ptr(ptr)
    {
    }

    ~ScopedPtr()
    {
        delete m_Ptr;
    }
};

int main() 
{
    {
        ScopedPtr e = new Entity(); 
        // Entity* e = new Entity();
    }

    return 0;
}