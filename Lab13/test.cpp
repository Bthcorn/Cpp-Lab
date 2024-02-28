#include <iostream>
#include <vector>

// Base class for objects with carbon footprints
class CarbonFootprint {
public:
    virtual double getCarbonFootprint() const = 0;
};

// Factory class
class Factory : public CarbonFootprint {
private:
    double productionHours;
    double energyPerHour;
    double wastePerHour;
    double conversionFactor; // Conversion factor for waste to carbon equivalent

public:
    Factory(double prodHours, double energyPerHr, double wastePerHr, double convFactor)
        : productionHours(prodHours), energyPerHour(energyPerHr), wastePerHour(wastePerHr), conversionFactor(convFactor) {}

    double getCarbonFootprint() const override {
        return (productionHours * energyPerHour) + (wastePerHour * conversionFactor);
    }
    ~Factory() {}
};

// ElectricCar class
class ElectricCar : public CarbonFootprint {
private:
    double batteryCapacity;
    double chargeEfficiency;

public:
    ElectricCar(double battCap, double chargeEff)
        : batteryCapacity(battCap), chargeEfficiency(chargeEff) {}

    double getCarbonFootprint() const override {
        // Assuming electric car's carbon footprint includes electricity consumption during charging
        // considering charging efficiency
        // Calculation may involve additional factors like the source of electricity (renewable vs non-renewable)
        // and its associated emissions.
        return batteryCapacity / chargeEfficiency;
    }
    ~ElectricCar() {}
};

// Enhanced Building class
class EnhancedBuilding : public CarbonFootprint {
private:
    double numberOfOccupants;
    double energyConsumptionPerOccupant;

public:
    EnhancedBuilding(double occupants, double energyPerOccupant)
        : numberOfOccupants(occupants), energyConsumptionPerOccupant(energyPerOccupant) {}

    double getCarbonFootprint() const override {
        // Assuming emissions are calculated based on energy consumption per occupant
        return numberOfOccupants * energyConsumptionPerOccupant;
    }
    ~EnhancedBuilding() {}
};

// Modified Car class
class ModifiedCar : public CarbonFootprint {
private:
    double fuelEfficiency;

public:
    ModifiedCar(double fuelEff)
        : fuelEfficiency(fuelEff) {}

    double getCarbonFootprint() const override {
        // Assuming emissions are inversely proportional to fuel efficiency
        // Lower fuel efficiency means higher emissions
        return 1.0 / fuelEfficiency;
    }
    ~ModifiedCar() {}
};

// Complex Bicycle class
class ComplexBicycle : public CarbonFootprint {
private:
    double manufacturingEmissions;

public:
    ComplexBicycle(double manufEmissions)
        : manufacturingEmissions(manufEmissions) {}

    double getCarbonFootprint() const override {
        // Assuming manufacturing emissions are the primary source of carbon footprint for bicycles
        // Compared to motorized vehicles, operational emissions are negligible for bicycles
        return manufacturingEmissions;
    }
    ~ComplexBicycle() {}
};

// Application class to manage and compute carbon footprints
class CarbonFootprintManager {
private:
    std::vector<CarbonFootprint*> objects;

public:
    void addObject(CarbonFootprint* obj) {
        objects.push_back(obj);
    }

    void displayCarbonFootprints() const {
        for (const auto& obj : objects) {
            std::cout << "Carbon Footprint: " << obj->getCarbonFootprint() << std::endl;
        }
    }

    double getTotalCarbonFootprint() const {
        double total = 0.0;
        for (const auto& obj : objects) {
            total += obj->getCarbonFootprint();
        }
        return total;
    }

    ~CarbonFootprintManager() {
        for (auto& obj : objects) {
            delete obj;
        }
    }
};

int main() {
    CarbonFootprintManager manager;

    // Add objects to the manager
    manager.addObject(new Factory(100, 50, 10, 2));
    manager.addObject(new ElectricCar(100, 90));
    manager.addObject(new EnhancedBuilding(50, 100));
    manager.addObject(new ModifiedCar(30));
    manager.addObject(new ComplexBicycle(5));

    // Display carbon footprints
    manager.displayCarbonFootprints();

    // Display total carbon footprint
    std::cout << "Total Carbon Footprint: " << manager.getTotalCarbonFootprint() << std::endl;


    return 0;
}
