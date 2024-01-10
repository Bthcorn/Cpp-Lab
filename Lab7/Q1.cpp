#include <iostream>
#include <array>
#include <string>
#include <iomanip>

// dishes "Pad Thai", "Som Tam", "Mango Sticky Rice", "Tom Yum Goong", and "Green Curry".
// respones[5][10]
const size_t dishSize{5};
const size_t ratingSize{11};
const std::array<std::string, dishSize> dishes{"Pad Thai", "Som Tam", "Mango Sticky Rice", "Tom Yum Goong", "Green Curry"};

void displayResults(const std::array<std::array<int, ratingSize> , dishSize>& responses);
void collecRatings(std::array<std::array<int, ratingSize> , dishSize>& responses);



int main() 
{
    std::array<std::array<int, ratingSize> , dishSize> responses{};

    // 5 polls
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << "Poll: " << i + 1 << std::endl;
        collecRatings(responses);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    displayResults(responses);
    
    return 0;
}

void displayResults(const std::array<std::array<int, ratingSize> , dishSize>& responses)
{
    std::cout << "Survey Results: " << std::endl;
    std::cout << std::setw(20) << std::left << "Dishes";
    for (size_t i = 1; i < ratingSize; i++)
    {
        std::cout << std::setw(5) << std::right << i;
    }
    std::cout << std::setw(10) << std::right << "Average";
    std::cout << std::endl;

    std::string highestDish;
    std::string lowestDish;
    double highest = 0;
    double lowest = 0;

    for (size_t i = 0; i < dishSize; i++)
    {
        int total = 0;
        std::cout << std::setw(20) << std::left << dishes[i];
        for (size_t j = 1; j < ratingSize; j++)
        {
            total += responses[i][j] * j;
            std::cout << std::setw(5) << std::right << responses[i][j];
        }
        double average = total / 5.0;
        std::cout << std::setw(10) << std::right << average;
        

        if (average > highest)
        {
            highest = average;
            highestDish = dishes[i];
        } else {
            lowest = average;
            lowestDish = dishes[i];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Highest Rated Dish: " << highestDish << " (Score: " << 5.0 * highest << ")" << std::endl;
    std::cout << "Lowest Rated Dish: " << lowestDish << " (Score: " << 5.0 * lowest << ")" << std::endl;
}

void collecRatings(std::array<std::array<int, ratingSize> , dishSize>& responses)
{
    size_t i = 0;
    while (true)
    {
        if (i == dishSize)
        {
            break;
        }

        int rating;
        std::cout << "Rate " << dishes[i] << " on a scale of 1 to 10: ";
        std::cin >> rating;
        while (true)
        {
            if (rating < 1 || rating > 10 || std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "Invalid rating. Please try again." << std::endl;
                std::cout << "Rate " << dishes[i] << " on a scale of 1 to 10: ";
                std::cin >> rating;
            } else {
                break;
            }
        
        }
        ++responses[i][rating];
        i++;
    }
}
    // for (size_t i = 0; i < dishSize; i++)
    // {
    //     int rating;
    //     std::cout << "Rate " << dishes[i] << " on a scale of 1 to 10: ";
    //     std::cin >> rating;
    //     if (rating < 1 || rating > 10)
    //     {
    //         std::cout << "Invalid rating. Please try again." << std::endl;
    //         i--;
    //         continue;
    //     }
    //     ++responses[i][rating];
    // }
    // if (rating < 1 || rating > 10)
    // {
    //     std::cout << "Invalid rating. Please try again." << std::endl;
    //     continue;
    // } 