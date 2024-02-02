#include <iostream>
#include <string>
#include <memory>

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

    void Print()
    {
        std::cout << "Printing Entity!" << std::endl;
    }
};

int main()
{
    {
        std::shared_ptr<Entity> e0;
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); //hold reference count, increase
            std::weak_ptr<Entity> weakEntity = sharedEntity; //won't increase reference count, like store reference
            e0 = sharedEntity;
        }
        // {
        //     // std::unique_ptr<Entity> entity(new Entity()); //define explicit
        //     std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        //     // std::unique_ptr<Entity> entity2 = entity; //error: use of deleted function
        //     std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); // allocate to store reference count
        //     std::shared_ptr<Entity> sharedEntity2 = sharedEntity;              // reference count +1
        //     entity->Print();
        // }
    }
}