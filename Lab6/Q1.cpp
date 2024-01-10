#include <iostream>
#include <string>
#include <vector>
#include <limits>

int smallest(std::vector<int> &v)
{
    int smallest = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < smallest)
        {
            smallest = v[i];
        }
    }
    return smallest;
}

int main()
{
    std::string input;
    std::vector<int> v;
    int number;
    int size;

    std::cout << "Enter the number of integers: ";
    std::cin >> input;
    try
    {
        size = std::stoi(input);
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "Invalid input." << std::endl;
        return 0;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Invalid input." << std::endl;
        return 0;
    }

    if (size < 0)
    {
        std::cout << "Invalid input." << std::endl;
        return 0;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character left in the buffer


    std::cout << "Enter an integer: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> input;
        try
        {
            number = std::stoi(input);
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "Invalid input." << std::endl;
            return 0;
        }
        v.push_back(number);
    }
    std::cout << "The smallest number is " << smallest(v) << std::endl;
}