#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

// declare classes
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
protected:
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
    WildPokemon(std::string name, std::string sound, std::string type, int power, int speed, int catchRate) : Pokemon(name, sound, type, power, speed), catchRate(catchRate)
    {
        escapeRate = speed * power % 100;
    }

    void setCatchRate(int catchRate) { this->catchRate = catchRate; }
    int getCatchRate() { return catchRate; }

    void attempEscape(std::vector<WildPokemon> &wildPoke3, int ballEff)
    {
        // std::random_device rd;
        // std::default_random_engine re(rd());
        // std::uniform_int_distribution<int> rand(0, 100);
        // int escapeRate = rand(re);
        std::cout << "The attempt rate is " << escapeRate << std::endl;
        if (escapeRate > ballEff)
        {
            std::cout << "The wild " << getName() << " escaped!" << std::endl;
            for (int i = 0; i < wildPoke3.size(); i++)
            {
                if (wildPoke3[i].getName() == getName())
                {
                    wildPoke3.erase(wildPoke3.begin() + i);
                }
            }
        }
    }

    // friend class World;
    // friend void World::explore(Player& player);
    // friend void World::removeWildPokemon(WildPokemon wildPokemon);
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

    // void decreaseCatchRate(WildPokemon pokemon, Pokeball pokeball)
    // {
    //     pokemon.setCatchRate(pokemon.getCatchRate() - effectiveness);
    //     pokeball.catchPokemon(pokemon);
    // }
};

class Player
{
private:
    std::vector<PalPokemon> palPoke;
    std::vector<Pokeball> pokeballs;
    std::vector<Berry> berries;

public:
    Player(std::vector<Pokeball> pokeballs, std::vector<Berry> berries) : pokeballs(pokeballs), berries(berries) {}

    void addPalPokemon(PalPokemon palPokemon) { palPoke.push_back(palPokemon); }

    void addPokeball(Pokeball pokeball) { pokeballs.push_back(pokeball); }

    void addRandomPokeball()
    {
        if (pokeballs.size() >= 5)
        {
            return;
        }
        else
        {
            std::random_device rd;
            std::default_random_engine re(rd());
            std::uniform_int_distribution<int> rand(0, 1);
            int effectiveness = rand(re);
            std::string name;
            switch (effectiveness)
            {
            case 0:
                effectiveness = 30;
                name = "Normal Pokeball";
                break;
            case 1:
                effectiveness = 70;
                name = "Ultra Pokeball";
                break;
            }
            pokeballs.push_back(Pokeball(name, effectiveness));
        }
    }

    void listPokeballs()
    {
        for (Pokeball pokeball : pokeballs)
        {
            std::cout << pokeball.getName() << " ";
            // with effectiveness   
            std::cout << pokeball.getEffectiveness() << std::endl;
        }
    }

    void listCurrentPokemon()
    {
        for (PalPokemon pokemon : palPoke)
        {
            std::cout << pokemon.getName() << std::endl;
        }
    }

    void addBerry(Berry berry) { berries.push_back(berry); }

    void catchPokemon(WildPokemon &pokemon, Pokeball &pokeball, std::vector<WildPokemon> &wildPoke)
    {
        bool caught = pokeball.catchPokemon(pokemon);
        if (caught)
        {
            std::cout << "Successfully caught " << pokemon.getName() << "! " << std::endl;
            addPalPokemon(PalPokemon(pokemon.getName(), pokemon.getSound(), pokemon.getType(), pokemon.getPower(), pokemon.getSpeed()));
            pokeballs.erase(pokeballs.begin());
            wildPoke.erase(wildPoke.begin());
        }
        else
        {
            pokemon.attempEscape(wildPoke, pokeballs[0].getEffectiveness());
            pokeballs.erase(pokeballs.begin());
        }
    }

    friend class World;
    friend class GameTester;
};

class World
{
public:
    std::vector<WildPokemon> wildPoke;
    World(std::vector<WildPokemon> wildPoke) : wildPoke(wildPoke) {}

    void addWildPokemon(WildPokemon wildPokemon) { wildPoke.push_back(wildPokemon); }

    // remove by passing name
    void removeWildPokemon(std::string name)
    {
        for (WildPokemon pokemon : wildPoke)
        {
            if (pokemon.getName() == name)
            {
                wildPoke.erase(wildPoke.begin());
            }
        }
    }

    void explore(Player &player)
    {
        // for (WildPokemon pokemon : wildPoke)
        // {
        // random if wild pokemon appears
        std::random_device rd;
        std::default_random_engine re(rd());
        std::uniform_int_distribution<int> rand(0, 3);
        int appear = rand(re);
        if (appear == 1)
        {
            std::cout << "A wild " << wildPoke[0].getName() << " appeared!" << std::endl;
            player.catchPokemon(wildPoke[0], player.pokeballs[0], wildPoke);
        }
        else
        {
            std::cout << "No Pokemon encoutered on this walk!" << std::endl;
        }

        // std::cout << "A wild " << wildPoke[0].getName() << " appeared!" << std::endl;
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
        // }
    }

    friend class GameTester;
    friend class WildPokemon;
};

class GameTester
{
private:
    std::vector<WildPokemon> *wildPoke;
    std::vector<PalPokemon> *palPoke;
    std::vector<Pokeball> *pokeballs;
    std::vector<Berry> *berries;
    Player *player;
    World *world;

public:
    GameTester(std::vector<WildPokemon> &wildPoke, std::vector<Pokeball> &pokeballs, std::vector<Berry> &berries, Player &player, World &world) : wildPoke(&wildPoke), pokeballs(&pokeballs), berries(&berries), player(&player), world(&world) {}

    void TestCatchMechanics()
    {
        std::cout << "Testing Catch Mechanics: " << std::endl;
        world->explore(*player);
    }

    void TestEscapeMechanics()
    {
        std::cout << "Testing Escape Mechanics: " << std::endl;
        world->explore(*player);
    }
};

int main()
{

    Pokeball pokeball1("Ultra Pokeball", 70);
    Pokeball pokeball2("Normal Pokeball", 30);
    Pokeball pokeball3("Normal Pokeball", 30);
    Pokeball pokeball4("Normal Pokeball", 30);
    Pokeball pokeball5("Normal Pokeball", 30);

    std::vector<Pokeball> pokeballs;

    Berry razzBerry("Razz Berry", 10);
    Berry pinapBerry("Pinap Berry", 20);
    std::vector<Berry> berries = {razzBerry, pinapBerry};

    Player player(pokeballs, berries);
    player.addPokeball(pokeball1);
    player.addPokeball(pokeball2);
    player.addPokeball(pokeball3);
    player.addPokeball(pokeball4);
    player.addPokeball(pokeball5);

    WildPokemon pidgey("Pidgey", "Pidge", "Flying", 7, 9, 50);
    WildPokemon rattata("Rattata", "Rat", "Normal", 9, 8, 60);
    WildPokemon caterpie("Caterpie", "Cater", "Bug", 10, 6, 50);
    std::vector<WildPokemon> wildPoke = {pidgey, rattata, caterpie};
    // show the wild pokemon
    World world(wildPoke);

    while(true)
    {
        std::cout << "Choose an action: " << std::endl; 
        std::cout << "1. Add Pokeball to stock" << std::endl;
        std::cout << "2. Walk" << std::endl;
        std::cout << "3. List Pokeballs" << std::endl;
        std::cout << "4. List caught Pokemon" << std::endl;
        std::cout << "5. Quit" << std::endl;

        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            player.addRandomPokeball();
            break;
        case 2:
            world.explore(player);
            break;
        case 3:
            player.listPokeballs();
            break;
        case 4:
            player.listCurrentPokemon();
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
        }
    }

    return 0;
}
