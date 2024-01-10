#include <iostream>

struct Entity
{
    static int x, y;

    static void Print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int Entity::x;
int Entity::y;

static void Print(Entity e)
{
    std::cout << e.x << ", " << e.y << std::endl;
}

int main()
{
    Entity e;
    Entity::x = 2;
    Entity::y = 3;
    // e.x = 2;
    // e.y = 3;

    Entity e1;
    Entity::x = 5;
    Entity::y = 8;
    // e1.x = 5;
    // e1.y = 8;

    Entity::Print();
    Entity::Print();
    return 0;
}