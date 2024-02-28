#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>

class CarbonFootprint
{
public:
    virtual double calculateCarbonFootprint() = 0;
    virtual ~CarbonFootprint() {}
    virtual void displayCarbonFootprint() = 0;
};

class Car : public CarbonFootprint
{
public:
    double fuelConsumption;
    double fuelEfficiency;

    Car(double fuelConsumption, double fuelEfficiency)
    {
        this->fuelConsumption = fuelConsumption;
        this->fuelEfficiency = fuelEfficiency;
    }

    ~Car() {} //

    double calculateCarbonFootprint() override
    {
        return fuelConsumption * fuelEfficiency * 0.0231;
    }

    void displayCarbonFootprint() override
    {
        std::cout << "Car Carbon Footprint: " << calculateCarbonFootprint() << " tons of CO" << "\n";
    }
};

class Building : public CarbonFootprint
{
public:

    double energyConsumption;
    double numberOfOccupants;

    Building(double energyConsumption, double numberOfOccupants)
    {
        this->energyConsumption = energyConsumption;
        this->numberOfOccupants = numberOfOccupants;
    }

    ~Building() {} //

    double calculateCarbonFootprint() override
    {
        return energyConsumption * numberOfOccupants / 10000 * 2.9;
    }

    void displayCarbonFootprint() override
    {
        std::cout << "Building Carbon Footprint: " << calculateCarbonFootprint() << " tons of CO" << "\n";
    }
};

class ElectricCar : public Car
{
public:
    double batteryCapacity;
    double chargeEfficiency;
    double energyConsumption;

    // fuel efficiency  = 0.0000725
    ElectricCar(double batteryCapacity, double energyConsumption, double chargeEfficiency) : Car(0, 0)
    {
        this->batteryCapacity = batteryCapacity;
        this->chargeEfficiency = chargeEfficiency;
        this->energyConsumption = energyConsumption;
    }

    ~ElectricCar() {} //   

    double calculateCarbonFootprint() override
    {
        return energyConsumption * (chargeEfficiency * batteryCapacity);
    }

    void displayCarbonFootprint() override
    {
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Electric Car Carbon Footprint: " << calculateCarbonFootprint() << " tons of CO" << "\n";
        // set decimal precision to 6

    }

};

class Factory : public CarbonFootprint
{
public:
    double productionHours;
    double energyPerHour;
    double wastePerHour;

    Factory(double productionHours, double energyPerHour, double wastePerHour)
    {
        this->productionHours = productionHours;
        this->energyPerHour = energyPerHour;
        this->wastePerHour = wastePerHour;
    }

    ~Factory() {} //

    double calculateCarbonFootprint() override
    {
        return productionHours * energyPerHour * wastePerHour;
    }

    void displayCarbonFootprint() override
    {
        std::cout << "Factory Carbon Footprint: " << calculateCarbonFootprint() << " tons of CO" << "\n";
    }
}; 

class Bicycle : public CarbonFootprint
{
public: 
    double manufacturingEmissions;

    Bicycle(double manufacturingEmissions)
    {
        this->manufacturingEmissions = manufacturingEmissions;
    }

    ~Bicycle() {} //

    double calculateCarbonFootprint() override
    {
        return manufacturingEmissions;
    }
    
    void displayCarbonFootprint() override
    {
        std::cout << "Bicycle Carbon Footprint: " << calculateCarbonFootprint() << " tons of CO" << "\n";
    }
};  
class displayCarbonFootprint
{
public:
    std::vector<std::unique_ptr<CarbonFootprint>> carbonFootprints;

    void addCarbonFootprint(CarbonFootprint* carbonFootprint)
    {
        carbonFootprints.push_back(std::unique_ptr<CarbonFootprint>(carbonFootprint));
    }

    void displayCarbonFootprints()
    {
        for (const auto &carbonFootprint : carbonFootprints)
        {
            carbonFootprint->displayCarbonFootprint();
        }
    }
};

void checkInputs(double &input1, double &input2)
{
    while (std::cin.fail() || input1 < 0 || input2 < 0)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input. Please enter a positive number: ";
        std::cin >> input1 >> input2;
    }
}



int main()
{
    displayCarbonFootprint displayCarbonFootprint;

    std::cout << "Enter Building's energy consumption (kWh) and number of occupants: ";
    double energyConsumption1, numberOfOccupants;
    std::cin >> energyConsumption1 >> numberOfOccupants;
    checkInputs(energyConsumption1, numberOfOccupants);
    displayCarbonFootprint.addCarbonFootprint(new Building(energyConsumption1, numberOfOccupants));

    std::cin.ignore();

    std::cout << "Enter Car's fuel consumption (liters) and fuel efficiency (km/liter): ";
    double fuelConsumption, fuelEfficiency;
    std::cin >> fuelConsumption >> fuelEfficiency;
    checkInputs(fuelConsumption, fuelEfficiency);
    displayCarbonFootprint.addCarbonFootprint(new Car(fuelConsumption, fuelEfficiency));

    std::cin.ignore();

    std::cout << "Enter Electric Car's energy consumption (kWh), charge efficiency (ratio): ";
    double chargeEfficiency, energyConsumption2;
    std::cin >> energyConsumption2 >> chargeEfficiency;
    checkInputs(energyConsumption2, chargeEfficiency);
    displayCarbonFootprint.addCarbonFootprint(new ElectricCar(0.0000725, energyConsumption2, chargeEfficiency));
    std::cin.ignore();

    displayCarbonFootprint.displayCarbonFootprints();

    return 0;
}