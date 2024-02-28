#include <iostream>
#include <vector>
#include <memory>
// Base class
class SpaceObject
{
public:
    virtual void draw() const
    {
        std::cout << "Drawing a generic space object.\n";
    }
    virtual ~SpaceObject() {}
};
// Derived classes
class Martian : public SpaceObject
{
public:
    void draw() const override
    {
        std::cout << "Drawing a Martian with green antennas.\n";
    }

    ~Martian() {}
};

class Venutian : public SpaceObject
{
public: 
    void draw() const override
    {
        std::cout << "Drawing a Venutian with a shiny, silver surface.\n";
    }
    ~Venutian() {}
};

class Plutonian : public SpaceObject
{
public: 
    void draw() const override
    {
        std::cout << "Drawing a Plutonian with a cold, blue glow.\n";
    }
    ~Plutonian() {}
};

class SpaceShip : public SpaceObject
{
public: 
    void draw() const override
    {
        std::cout << "Drawing a SpaceShip with sleek, aerodynamic wings.\n";
    }
    ~SpaceShip() {}
};

class LaserBeam : public SpaceObject
{
public: 
    void draw() const override
    {
        std::cout << "Drawing a LaserBeam with a bright, red streak.\n";
    }
    ~LaserBeam() {} 
};

class Mercurian : public SpaceObject
{   
public: 
    void draw() const override
    {
        std::cout << "Drawing a Mercurian with a swift, silver shadow.\n";
    }
    ~Mercurian() {}
};
// Add other derived classes here...
// ScreenManager class
class ScreenManager
{

    std::vector <SpaceObject*> objects;

public:
    void addObject(SpaceObject* obj)
    {
        objects.push_back(std::move(obj));
    }
    void refreshScreen()
    {
        for (const auto &obj : objects)
        {
            obj->draw();
        }
    }
};
// Main function to demonstrate functionality
int main()
{
    ScreenManager manager;
    Martian m;
    Venutian v;
    Plutonian p;
    SpaceShip s;
    LaserBeam l;
    // Mercurian me;
    // Add objects to the manager and refresh the screen
    manager.addObject(&m);
    manager.addObject(&v);
    manager.addObject(&p);
    manager.addObject(&s);
    manager.addObject(&l);
    // manager.refreshScreen();
    // Demonstrate adding a Mercurian object
    manager.refreshScreen();
    manager.addObject(new Mercurian());
    manager.refreshScreen();
    
    return 0;
}