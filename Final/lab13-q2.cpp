#include <iostream>
#include <vector>
#include <memory>

class CarbonFootprint {
public:
    virtual ~CarbonFootprint() = default;
    virtual void getCarbonFootprint() {}
    virtual void enterAttribute() {}
};

class Car : public CarbonFootprint {
private: 
    double fuelConsumption;
    double fuelEfficiency;
public:
    void getCarbonFootprint() override {
        std::cout << "Car Carbon Footprint: " << (fuelConsumption / fuelEfficiency) * 2.31 << " tons of C02.\n"; 
    }
    
    void enterAttribute() {
        std::cout << "Enter Car's fuel consumption (liters) and fule efficiency (km/liter): ";
        std::cin >> fuelConsumption >> fuelEfficiency;
    }
};

class ElectricCar : public CarbonFootprint {
private: 
    double energyConcumption;
    double energyEfficiency;
    double batteryCapacity;
    double chargesEfficiency;
public:
    void enterAttribute() override {
        std::cout << "Enter Electic Car's energy consumption (kWh), charge efficiency (ratio): ";
        std::cin >> energyConcumption >> chargesEfficiency;
    }

    void getCarbonFootprint() override {
        std::cout << "Electric Car's Carbon Footprint: " << (energyConcumption * (1 - chargesEfficiency) * 0.00029) << " tons of CO2.\n";
    }
};

class Building : public CarbonFootprint {
private:
    double energyConsumption;
    int numberofOccupants;

public:
    void enterAttribute() override {
        std::cout << "Enter Building's energy consumption (kWh) and number of occupants: ";
        std::cin >> energyConsumption >> numberofOccupants;
    }

    void getCarbonFootprint() override {
        std::cout << "Building's Carbon Footprint: " << (energyConsumption * numberofOccupants * 0.00029) << " tons of CO2.\n";
    }
};

int main() {
    std::vector<std::shared_ptr<CarbonFootprint>> objects;

    auto building = std::make_shared<Building>();
    building->enterAttribute();
    objects.push_back(std::move(building));

    auto car = std::make_shared<Car>();
    car->enterAttribute();
    objects.push_back(std::move(car));

    auto electricCar = std::make_shared<ElectricCar>();
    electricCar->enterAttribute();
    objects.push_back(std::move(electricCar));

    for (const auto &obj: objects) {
        obj->getCarbonFootprint();
    }
    return 0;

}