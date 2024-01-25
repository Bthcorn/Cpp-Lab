#include <iostream>
#include <string>
#include <sstream>

class PopulatioGrouwth
{
    private:
    double initialPopulation;
    double growthRate;
    public:
    PopulatioGrouwth(double initialPopulation, double growthRate) : initialPopulation(initialPopulation), growthRate(growthRate) {}

    void displayGrowth(int years)
    {
        bool doubled = true;
        double currentPopulation = initialPopulation;
        double difference;
        std::cout << "Year" << "\t" << "Population" << "\t" << "Difference" << std::endl;

        for (int i = 1; i <= years; ++i)
        {
            difference = currentPopulation * (growthRate / 100);
            currentPopulation += difference;
            std::cout << i << "\t" << toString(currentPopulation) << "\t" << toString(difference) << std::endl;
            if (currentPopulation >= 2*initialPopulation && doubled)
            {
                std::cout << "This is double the initial population" << std::endl;
                doubled = false;
            }

            
        }
    }

    static std::string toString(double number)
    {
        std::string numStr = std::to_string(static_cast<long long>(number));
        int n = numStr.length() - 3;
        while (n > 0) {
            numStr.insert(n, ",");
            n -= 3;
        }
        return numStr;
    }

};

int main() {
    std::string input;
    double initialPopulation;
    double growthRate;
    std::cout << "Enter initial population: ";
    std::cin >> input;
    initialPopulation = std::stod(input);

    std::cout << "Enter growth rate: ";
    std::cin >> input;
    growthRate = std::stod(input);


    PopulatioGrouwth population(initialPopulation, growthRate);
    population.displayGrowth(75);
}