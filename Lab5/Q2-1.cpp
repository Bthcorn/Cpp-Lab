#include <iostream>
#include <iomanip>
#include <cmath>

class PopulationGrowth{
    private:
        double initialPopulation;
        float growthRate;
    public:
        PopulationGrowth(double initialPopulation, double growthRate);
        void displayGrowth();   
};



PopulationGrowth::PopulationGrowth(double initialPopulation, double growthRate){
    this->initialPopulation = initialPopulation;
    this->growthRate = growthRate;
}


void PopulationGrowth::displayGrowth(){
    std::cout << "\nYear\t Projected Population\t Annual Increase" << std::endl;
    double newinitialPolulation = initialPopulation;
    int year = 75;
    bool s = true;
    while (true)
    {
        if (year <= 0) {
            break;
        }
        double projectedPopulation = initialPopulation * pow((1+growthRate/100), 75 - year + 1);
        double annual = projectedPopulation - newinitialPolulation;
        std::cout << 75 - year + 1 << "\t " << std::fixed << std::setprecision(0)<< (long long)projectedPopulation << "\t " << std::fixed<< std::setprecision(0)<< (long long) annual <<std::endl;
        if (projectedPopulation >= (initialPopulation * 2) && s == true) {
            std::cout << "----------------------------------------" << std::endl;
            s = false;
        }
        year--;
        newinitialPolulation = projectedPopulation;
    }
}

int main() {
    double initialPopulation;
    double growthRate;
    std::cout << "Enter the current world popultaion: ";
    std::cin >> initialPopulation;
    std::cout << "Enter the annual growth rate (percentage): ";
    std::cin >> growthRate;
    PopulationGrowth populationGrowth(initialPopulation, growthRate);
    populationGrowth.displayGrowth();

    return 0;
}