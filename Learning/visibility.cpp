#include <iostream>

class Entity //defualt private but struct is public
{
// private:
//     int X, Y;
// protected: //only accessible by this class and subclass
public:
    int X, Y;
    void Print() {}

public:
    Entity()
    {
        X = 0;
        Y = 0;
        Print();
    }
};

class Player : public Entity
{
public:
    Player()
    {
        X = 2; //error
        Print();
    }
};

int main() {
    Entity e;
    e.Print();
    
    return 0;
}