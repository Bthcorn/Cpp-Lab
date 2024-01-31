#include <iostream>
#include <random>
#include <ctime>
#include <array>

typedef std::array<std::array<int, 3>, 3> matrix;

class GuessNumberGame
{
private:
    int number = rand() % 100 + 1;
    int tries = 0;
public:
    int guess;
    GuessNumberGame(int number, int t) : number(number), tries(t) {}
    int getNumber()
    {
        return number;
    }

    int getTries()
    {
        return tries;
    }
    void tryAgian()
    {
        std::cout << "Try again: ";
        std::cin >> guess;
        if (std::cin.fail())
        {
            std::cout << "Invalid input" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            tryAgian();
        }
    }
    
    void play()
    {
        std::cout << "Guess a number between 0 to 100: ";
        std::cin >> guess;
        int t = 1;
        while(true)
        {
            if (std::cin.fail())
            {
                std::cout << "Invalid input" << std::endl;
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "Guess a number between 0 to 100: ";
                tryAgian();
            }
            if (t == tries)
            {
                std::cout << "You lose!" << std::endl;
                std::cout << "The number was " << number << std::endl;
                break;
            } else if (guess == number)
            {
                std::cout << "You win!" << std::endl;
                std::cout << "You guessed it in " << t << " tries" << std::endl;
                std::cout << "The number was " << number << std::endl;
                break;
            } else if (guess > number)
            {
                std::cout << "Too high" << std::endl;
                tryAgian();
            } else 
            {
                std::cout << "Too low" << std::endl;
                tryAgian();
            }
            t++;
        }
    }
};

int main()
{
    // srand(static_cast<unsigned int>(std::time(nullptr)));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    GuessNumberGame g(dis(gen), 10);
    g.play();
    // std::cout << g.getNumber() << std::endl;
    return 0;
}