#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

//declare classes
class World;
class Pokemon;
class WildPokemon;
class PalPokemon;
class Pokeball;
class Berry;
class Player;
class GameTester;



class Pokemon 
{
private:
    std::string name;
    std::string sound;
    std::string type;
    int power;
    int speed;
public:
    Pokemon(std::string name, std::string sound, std::string type, int power, int speed) : name(name), sound(sound), type(type), power(power), speed(speed) {}

    void setName(std::string name) { this->name = name; }
    std::string getName() { return name; }

    void setSound(std::string sound) { this->sound = sound; }
    std::string getSound() { return sound; }

    void setType(std::string type) { this->type = type; }
    std::string getType() { return type; }

    void setPower(int power) { this->power = power; }
    int getPower() { return power; }

    void setSpeed(int speed) { this->speed = speed; }
    int getSpeed() { return speed; }
};

class WildPokemon : public Pokemon
{
private:
    int catchRate;
    int escapeRate;
public:
    WildPokemon(std::string name, std::string sound, std::string type, int power, int speed, int catchRate, int escapeRate) : Pokemon(name, sound, type, power, speed), catchRate(catchRate), escapeRate(escapeRate) {}

    void setCatchRate(int catchRate) { this->catchRate = catchRate; }
    int getCatchRate() { return catchRate; }

    void attempEscape(World& world)
    {
        // std::random_device rd;
        // std::default_random_engine re(rd());
        // std::uniform_int_distribution<int> rand(0, 100);
        // escapeRate = rand(re);
        if (escapeRate > 50) 
        {
            std::cout << "The wild " << getName() << " escaped!" << std::endl;
            // world.removeWildPokemon(*this);
        }
    }
};

class PalPokemon : public Pokemon
{
public:
    PalPokemon(std::string name, std::string sound, std::string type, int power, int speed) : Pokemon(name, sound, type, power, speed) {}

    void usePotion() {}
};

class Pokeball 
{
private:
    std::string name;
    int effectiveness;
public:
    Pokeball(std::string name, int effectiveness) : name(name), effectiveness(effectiveness) {}

    void setName(std::string name) { this->name = name; }
    std::string getName() { return name; }

    void setEffectiveness(int effectiveness) { this->effectiveness = effectiveness; }
    int getEffectiveness() { return effectiveness; }

    bool catchPokemon(WildPokemon pokemon) 
    {
        if (effectiveness > pokemon.getCatchRate()) 
        {
            std::cout << "You caught " << pokemon.getName() << "!" << std::endl;
            return true;
        } 
        else 
        {
            std::cout << "You failed to catch " << pokemon.getName() << "!" << std::endl;
            return false;
        }
    }
};

class Berry
{
private:
    std::string name;
    int effectiveness;
public:
    Berry(std::string name, int effectiveness) : name(name), effectiveness(effectiveness) {}

    void setName(std::string name) { this->name = name; }
    std::string getName() { return name; }

    void setEffectiveness(int effectiveness) { this->effectiveness = effectiveness; }
    int getEffectiveness() { return effectiveness; }

    void decreaseCatchRate(WildPokemon pokemon, Pokeball pokeball) 
    {
        pokemon.setCatchRate(pokemon.getCatchRate() - effectiveness);
        pokeball.catchPokemon(pokemon);
    }

};

class Player
{
private:
    std::vector<PalPokemon> palPoke;
    std::vector<Pokeball> pokeballs;
    std::vector<Berry> berries;
public:
    Player(std::vector<PalPokemon> palPoke, std::vector<Pokeball> pokeballs, std::vector<Berry> berries) : palPoke(palPoke), pokeballs(pokeballs), berries(berries) {}


    void addPalPokemon(PalPokemon palPokemon) { palPoke.push_back(palPokemon); }

    void addPokeball(Pokeball pokeball) { pokeballs.push_back(pokeball); }

    void addBerry(Berry berry) { berries.push_back(berry); }

    void catchPokemon(WildPokemon& pokemon, Pokeball& pokeball, World& world) 
    { 
        bool caught = pokeball.catchPokemon(pokemon); 
        if (caught) 
        {
            addPalPokemon(PalPokemon(pokemon.getName(), pokemon.getSound(), pokemon.getType(), pokemon.getPower(), pokemon.getSpeed()));
            pokeballs.erase(pokeballs.begin());
        } else 
        {
            pokemon.attempEscape(world);
            pokeballs.erase(pokeballs.begin());
        }
    
    }

    friend class World;
    friend class GameTester;
};

class World
{
private:
    std::vector<WildPokemon> wildPoke;
public:
    World(std::vector<WildPokemon> wildPoke) : wildPoke(wildPoke) {}

    void addWildPokemon(WildPokemon wildPokemon) { wildPoke.push_back(wildPokemon); }

    void removeWildPokemon(WildPokemon wildPokemon) 
    {
        for (int i = 0; i < wildPoke.size(); i++) 
        {
            if (wildPoke[i].getName() == wildPokemon.getName()) 
            {
                wildPoke.erase(wildPoke.begin() + i);
            }
        }
    }



    void explore(Player& player)
    {
        // for (WildPokemon pokemon : wildPoke) 
        // {
            std::cout << "A wild " << wildPoke[0].getName() << " appeared!" << std::endl;
            // std::cout << "What will you do?" << std::endl;
            // std::cout << "1. Catch" << std::endl;
            // std::cout << "2. Run" << std::endl;
            // int choice;
            // std::cin >> choice;
            // if (choice == 1) 
            // {
            //     std::cout << "Which pokeball will you use?" << std::endl;
            //     for (Pokeball pokeball : player.pokeballs) 
            //     {
            //         std::cout << pokeball.getName() << std::endl;
            //     }
            //     std::string pokeballName;
            //     std::cin >> pokeballName;
            //     for (Pokeball pokeball : player.pokeballs) 
            //     {
            //         if (pokeball.getName() == pokeballName) 
            //         {
            //             player.catchPokemon(pokemon, pokeball);
            //         }
            //     }
            // }
            player.catchPokemon(wildPoke[0], player.pokeballs[0], *this);
        // }
    }

    friend class GameTester;
    friend class WildPokemon;
};

// class GameTester
// {
//     void explore(Player player, World world)
//     {
//         std::cout << "Testing Catch Mechanics: " << std::endl;
//         world.explore(player);
//         std::cout << "Testing Escape Mechanics: " << std::endl;
//         world.explore(player);
//     }

// };

int main() 
{
    PalPokemon charmander("Charmander", "Char", "Fire", 10, 10);
    PalPokemon squirtle("Squirtle", "Squirt", "Water", 10, 10);
    PalPokemon bulbasaur("Bulbasaur", "Bulba", "Grass", 10, 10);
    std::vector<PalPokemon> palPoke = {charmander, squirtle, bulbasaur};

    Pokeball pokeball("Greatball", 70);
    Pokeball greatball("Pokeball", 50);
    std::vector<Pokeball> pokeballs = {pokeball, greatball};

    Berry razzBerry("Razz Berry", 10);
    Berry pinapBerry("Pinap Berry", 20);
    std::vector<Berry> berries = {razzBerry, pinapBerry};

    Player player(palPoke, pokeballs, berries);

    WildPokemon pidgey("Pidgey", "Pidge", "Flying", 10, 10, 50, 50);
    WildPokemon rattata("Rattata", "Rat", "Normal", 10, 10, 50, 60);
    WildPokemon caterpie("Caterpie", "Cater", "Bug", 10, 10, 50, 50);
    std::vector<WildPokemon> wildPoke = {pidgey, rattata, caterpie};

    World world(wildPoke);

    // GameTester gameTester;
    // gameTester.explore(player, world);
    std::cout << "Testing Catch Mechanics: " << std::endl;
    world.explore(player);
    std::cout << std::endl;
    std::cout << "Testing Escape Mechanics: " << std::endl;
    world.explore(player);

    return 0;
}

