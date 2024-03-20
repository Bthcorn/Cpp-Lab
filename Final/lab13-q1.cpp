#include <iostream>
#include <vector>
#include <string>
#include <memory>

class SpaceObject {
public:
    virtual ~SpaceObject() = default;
    virtual void draw() {
        std::cout << "Drawing a generic space object.\n";
    }
};

class Martian : public SpaceObject {
public: 
    void draw() override {
        std::cout << "Drawing a Martian with green antennas.\n";
    }
};


class Venutian : public SpaceObject {
public: 
    void draw() override {
        std::cout << "Drawing a Venutian with a shiny, silver surface.\n";
    }
};


class Plutonian : public SpaceObject {
public: 
    void draw() override {
        std::cout << "Drawing a Plutonian with a cold, blue glow.\n";
    }
};



class SpaceShip : public SpaceObject {
public: 
    void draw() override {
        std::cout << "Drawing a SpaceShip with sleek, aerodynamic wings.\n";
    }
};


class LaserBeam : public SpaceObject {
public: 
    void draw() override {
        std::cout << "Drawing a LaserBeam with a bright, red streak.\n";
    }
};

class Mercurian : public SpaceObject {
    void draw() override {
        std::cout << "Drawing a Mercurian with a swift, silver shadow.\n";
    }
};

class ScreenManager {
private:
    std::vector<SpaceObject*> objects;
public:
    void addObject(SpaceObject* obj) {
        objects.push_back(std::move(obj));
    }

    void refreshScreen() {
        for (const auto &obj : objects) {
            obj->draw();
        }
    }

    ~ScreenManager() {
        for (auto &obj : objects) {
            delete obj;
        }
    }
};

int main() {
    ScreenManager screen;
    screen.addObject(new Martian());
    screen.addObject(new Venutian());
    screen.addObject(new Plutonian());
    screen.addObject(new SpaceShip());
    screen.addObject(new LaserBeam());
    screen.addObject(new Mercurian());



    screen.refreshScreen();
    return 0;
}