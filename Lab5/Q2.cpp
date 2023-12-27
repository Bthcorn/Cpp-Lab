#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>

class PopulationGrowth
{
private:
    double init_population;
    double growth_rate;

public:
    double init_population2;
    double projected_population;
    void setInitPopulation(double init_population)
    {
        this->init_population = init_population;
        this->init_population2 = init_population;
    }

    void setGrowthRate(double growth_rate)
    {
        this->growth_rate = growth_rate;
    }

    void setProjectedPopulation(double projected_population)
    {
        this->projected_population = projected_population;
    }

    void setInitPopulation2(double init_population2)
    {
        this->init_population2 = init_population2;
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

    void checkDouble()
    {
        if (getProjectedPopulation() >= (2 * init_population2))
        {
            std::cout << "It's doubled!";
        }
        else if (getProjectedPopulation() >= (2 * init_population2 * 1.9))
        {
            std::cout << "It's doubled!";
        }
    }
};

int main()
{
    std::string input;
    PopulationGrowth populationGrowth;

    std::cout << "Enter the current world popuation: ";
    std::cin >> input;
    double current_population = std::stod(input);
    populationGrowth.setInitPopulation(current_population);
    populationGrowth.setInitPopulation2(current_population);

    std::cout << "Enter the annual growth rate (percentage): ";
    std::cin >> input;
    double growth_rate = std::stod(input);
    populationGrowth.setGrowthRate(growth_rate);

    bool a = true;

    std::cout << std::setw(4) << "Year" << std::setw(20) << "Projected Population" << std::setw(20) << "Annual Increase"
              << "\n";
    unsigned int i = 1;
    // insert comma in double

    while (i <= 75)
    {
        //  check eif it doubled
        populationGrowth.checkDouble();
        std::cout << std::setw(4) << i << std::fixed << std::setprecision(0) << std::setw(20) << populationGrowth.getProjectedPopulation() << std::setw(20) << populationGrowth.getAnnualIncrease() << "\n";
        if (populationGrowth.getProjectedPopulation() >= (2 * populationGrowth.getInitPopulation2()) && a == true)
        {
            std::cout << "I----------------------------------------\n";
            a = false;
        }
        populationGrowth.setInitPopulation(populationGrowth.getProjectedPopulation());

        i++;
    }

    return 0;
}