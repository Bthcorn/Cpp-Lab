#include <iostream>
#include <string>


class Entity
{
private:
    int m_X, m_Y;
    int* m_Z;
    mutable int var;
public:
    int GetX() const // const means that the function cannot change the value of the class
    {
        var = 2;
        return m_X;
    }
    int GetX()
    {
        return m_X;
    }

    void SetX(int x)
    {
        m_X = x;
    }
};

void PrintEntity(const Entity& e) // reference cannot be changed
{
    std::cout << e.GetX() << std::endl; // using const in GetX() allows this
}

int main()
{
    Entity e;
    PrintEntity(e);
    const int MAX_AGE = 90;

    int* a = new int; // cannot change the value of a
    // int* const a = new int; cannot reassign a to point to another address

    *a = 2;
    a = (int*)&MAX_AGE;
    std::cout << *a << std::endl;
    return 0;
}