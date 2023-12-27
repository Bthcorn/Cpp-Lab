#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class PopulationGrowth
{
private:
    double init_population;
    double init_population2;
    double growth_rate;

public:
    PopulationGrowth(double init_population, double growth_rate)
    {
        this->init_population = init_population;
        this->init_population2 = init_population;
        this->growth_rate = growth_rate;
    }

    double getInitPopulation() const
    {
        return init_population;
    }

    double getInitPopulation2() const
    {
        return init_population2;
    }

    double getGrowthRate() const
    {
        return growth_rate;
    }

    double getProjectedPopulation() const
    {
        return init_population * (1 + growth_rate / 100.0);
    }

    double getAnnualIncrease() const
    {
        return getProjectedPopulation() - init_population;
    }

    void setInitPopulation(double init_population)
    {
        this->init_population = init_population;
    }

    void setInitPopulation2(double init_population2)
    {
        this->init_population2 = init_population2;
    }

    void setGrowthRate(double growth_rate)
    {
        this->growth_rate = growth_rate;
    }
};

int main()
{
    double init_population;
    double growth_rate;

    std::string input;

    std::cout << "Enter the current world population: ";
    std::getline(std::cin, input);
    std::stringstream(input) >> init_population;

    std::cout << "Enter the annual growth rate (percentage): ";
    std::getline(std::cin, input);
    std::stringstream(input) >> growth_rate;

    PopulationGrowth populationGrowth(init_population, growth_rate);

    std::cout << "Year"
              << "      "
              << "Projected Population"
              << "    "
              << "Annual Increase" << std::endl;
    int num = 1;
    bool found = true;
    // insert comma in std::cout
    // std::cout.imbue(std::locale(""));


    while (num < 76)
    {

        std::cout << std::setw(4) << num << std::setw(20) << std::fixed << std::setprecision(0) << populationGrowth.getProjectedPopulation() << std::setw(20) << std::fixed << std::setprecision(0) << populationGrowth.getAnnualIncrease() << std::endl;
        
        num++;
        populationGrowth.setInitPopulation(populationGrowth.getProjectedPopulation());

        if (populationGrowth.getProjectedPopulation() >= (2 * populationGrowth.getInitPopulation2()) && found == true)
        {
            std::cout << "Found double!" << std::endl;
            found = false;
        }
    }

    return 0;
}