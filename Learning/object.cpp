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
    Entity* e;
    {
        Entity* entity = new Entity("Cherno");
        e = entity;
        cout << (*entity).GetName() << endl;
        // cout << entity->GetName() << endl;
    }
    delete e;
    return 0;
}
