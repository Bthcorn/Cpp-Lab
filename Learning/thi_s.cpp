#include <iostream>
#include <string>

class Entity 
{
public:
    int x, y;

    // Entity(int x, int y) : x(x), y(y) {}
    Entity(int x, int y)
    {
        // Entity* e = this;
        // e->x = x;
        // e->y = y;
        // (*this).x = x;
        this->x = x;
        this->y = y;
        Entity& e = *this;
        PrintEntity(*this);
    }

    int GetX() const
    {
        // const Entity* e = this;
        // return e->x;
        return x;
    }

    int GetY() const
    {
        // const Entity* e = this;
        // return e->y;
        return y;
    }
};

void PrintEntity(const Entity& e)
{
    std::cout << e.GetX() << ", " << e.GetY() << std::endl;
}

int main() 
{

}