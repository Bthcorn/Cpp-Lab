#include <iostream>
#include <vector>

class QuizQuestion
{
public:
    std::vector<std::string> questions = {"What is the capital of France?", 
    "Which planet is known as the Red Planet?", 
    "What is the largest mammal?", 
    "Who wrote \'Hamlet\'?", 
    "What is the chemical symbol of water?"};
    std::vector<std::vector<std::string>> choices = {{"Berlin", "Paris", "London"}, 
    {"Mars", "Jupiter", "Saturn"}, 
    {"Elephant", "Blue Whale", "Giraffe"}, 
    {"Mark Twain", "Charles Dickens", "William Shakespeare"}, 
    {"H2O", "CO2", "O2"}};
    // std::vector<int> answers = {1, 0, 1, 2, 0};
    std::vector<char> userAnswers = {'b', 'a', 'b', 'c', 'a'};
    int scores = 0;
    std::vector<std::string> abc = {"a", "b", "c"};

    // int getAnswer(int i) const
    // {
    //     return answers[i];
    // }

    void displayQuestion(int i)
    {
        std::cout << "Question " << i + 1 << ": " << questions[i] << std::endl;
        std::cout << "a) " << choices[i][0] << std::endl;
        std::cout << "b) " << choices[i][1] << std::endl;
        std::cout << "c) " << choices[i][2] << std::endl;
    }

    void checkAnswer(int i, char answer)
    {
        switch (answer)
        {
        case 'a':
            checkChoice(i, 'a');
            break;

        case 'b':
            checkChoice(i, 'b');
            break;

        case 'c':
            checkChoice(i, 'c');
            break;

        default:
            std::cout << "Invalid choice." << std::endl;
            break;
        }
    }

    void checkChoice(int i, char choice)
    {
        if (userAnswers[i] == choice)
        {
            scores++;
            std::cout << "Correct!" << std::endl;
        }
        else
        {
            scores = scores;
            std::cout << "Wrong answer." << std::endl;
            
        }
    }
};

int main()
{
    QuizQuestion q;
    int i = 0;
    while (true)
    {

        if (i == 5)
        {
            std::cout << "Your score is " << q.scores << std::endl;
            break;
        }

        q.displayQuestion(i);
        char answer;
        while (true) {
            std::cout << "Your answer (a, b, c): ";
            std::cin >> answer;
            if (answer == 'a' || answer == 'b' || answer == 'c') {
                break;
            } else {
                std::cout << "Invalid choice." << std::endl;
            }
        
        }

        q.checkAnswer(i, answer);
        std::cout << std::endl;
        i++;
    }
}