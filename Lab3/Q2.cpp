#include <iostream>
#include <random>

// class Rand_int {
//     private:
//         std::default_random_engine re;
//         std::uniform_int_distribution<int> dist;

//     public:
//         Rand_int(int low, int high) : re{}, dist{low, high} {
//             std::random_device rd;
//             re.seed(rd());
//         }
        
//         int operator()() { return dist(re); }

// };

class GuessNumberGame {
    private:
        int tries;
        int number = rand() % 100 + 1;

    public:
        GuessNumberGame(int tries) : tries(tries) {}
        int guess;
        
        void setTries(int t) {
            tries = t;
        }

        // void setNumber() {
        //     Rand_int r(0, 100);
        //     int n = r();
        //     number = n;
        // }

        void setGuess(int g) {
            guess = g;
        }

        int getTries() {
            return tries;
        }

        int getNumber() {
            return number;
        }

        int getGuess() {
            return guess;
        }

        void tryAgain() {
            std::cout << "Try again: ";
            int g;
            std::cin >> g;
            if (std::cin.fail()) {
                std::cout << "Invalid input" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            setGuess(g);

        }

        void play() {
            int guess;
            std::cout << "Guess a number between 0 and 100: ";
            std::cin >> guess;
            setGuess(guess);
            int t = 1;
            while (true) {
                if (std::cin.fail()) {
                    std::cout << "Invalid input" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    tryAgain();
                }
                // std::cout << "The number is " << getNumber() << std::endl;
                if (t == getTries()) {
                    std::cout << "You ran out of tries! lose." << std::endl;
                    std::cout << "The number was " << getNumber() << std::endl;
                    break;
                } else
                if (getGuess() == getNumber()) {
                    std::cout << "COngratulations! win. ";
                    break;
                } else if (getGuess() > getNumber()) {
                    std::cout << "Your guess is too high. ";
                    tryAgain();
                } else if (getGuess() < getNumber()) {
                    std::cout << "Your guess is too low. ";
                    tryAgain();
                }
                t++;
            }
        }

};


int main() {
    GuessNumberGame g(10);
    // g.setNumber();
    g.play();
    return 0;
}