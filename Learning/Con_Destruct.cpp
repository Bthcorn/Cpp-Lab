#include <iostream>

class Entity
{
public:
    float X, Y;
    
    Entity()
    {
        X = 0.0f;
        Y = 0.0f;
        std::cout << "Created Entity!" << std::endl;
    }

    Entity(float x, float y)
    {
        X = x;
        Y = y;
    }

    // void Init()
    // {
    //     X = 0.0f;
    //     Y = 0.0f;
    // }

    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }

    void Print() 
    {
        std::cout << X << ", " << Y << std::endl;
    }
};

class Log
{
public:
    Log() = delete;

    static void Write()
    {
        std::cout << "Hello!" << std::endl;
    }
    
};

void Function()
{
    Entity e;
    e.Print();
    // e.~Entity();
}

int main()
{
    // Entity e(10.0f, 5.0f);
    // e.Init();
    // std::cout << e.X << std::endl;
    // e.Print();
    Function();

    return 0;
}