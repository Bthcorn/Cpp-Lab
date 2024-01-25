#include <iostream>

class TemperatureConverter
{
private:
    double degree;
public:
    // TemperatureConverter(double d) : degree{d} {};
    double getDegree() const
    {
        return degree;
    }

    void setDegree(double& d)
    {
        degree = d;
    }

    double FartoCel() {
        return 1.8 * degree + 32;
    }

    double CeltoFar() {
        return (degree - 32) / 1.8;
    }
};

int main()
{
    TemperatureConverter converter;
    while(true)
    {
        double temp;
        std::cout << "Enter temperature: ";
        std::cin >> temp;
        if (std::cin.fail())
        {
            std::cout << "Invalid input" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            continue;
        }
        
        converter.setDegree(temp);
        while(true)
        {
            std::cout << "Convert to (F)ahrenheit or (C)elsius? ";
            char choice;
            std::cin >> choice;
            if (choice == 'F' || choice == 'f')
            {
                std::cout << converter.FartoCel() << std::endl;
                break;
            } else if (choice == 'C' || choice == 'c')
            {
                std::cout << converter.CeltoFar() << std::endl;
                break;
            } else 
            {
                std::cout << "Invalid choice" << std::endl;
                continue;
            }
        }
        std::cout << "Continue? (y/n) ";
        char cont;
        std::cin >> cont;
        if (cont == 'y' || cont == 'Y')
        {
            continue;
        } else 
        {
            break;
        }
    }


}