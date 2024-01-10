#include <iostream>
#include <string>

class Printable //interfaces subclass need to implement all the methods in the interface
{
public:
    virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
    virtual std::string GetName() { return "Entity"; }
    std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity
{
private:
    std::string m_Name;
public:
    Player(const std::string &name)
        : m_Name(name) {}

    std::string GetName() override { return m_Name; }
    std::string GetClassName() override { return "Player"; }
};

void PrintName(Entity* entity)
{
    std::cout << entity->GetName() << std::endl;
}

void Print(Printable* obj)
{
    std::cout << obj->GetClassName() << std::endl;
}

class A : public Printable
{
public:
    std::string GetClassName() override { return "A"; }
};

int main()
{
    Entity* e = new Entity();
    std::cout << e->GetName() << std::endl;
    // PrintName(e);

    Player* p = new Player("Cherno");
    std::cout << p->GetName() << std::endl;
    // PrintName(p);

    Entity* entity = p;
    std::cout << entity->GetName() << std::endl;

    Print(e);
    Print(p);
    Print(entity);
    Print(new A());

    std::cin.get();
}