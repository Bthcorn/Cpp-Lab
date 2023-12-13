#include <iostream>

class TemperatureConverter {
    private:
        double temp;
    
    public:
        TemperatureConverter(int temp) : temp(0) {}

        void setTemp(int t) {
            temp = t;
        }  

        double CeltoFah() {
            double convert = (temp * 9/5) + 32;
            return convert;
        }

        double FahtoCel() {
            double convert = (temp - 32) * 5/9;
            return convert;
        }
};

int main() {
    while (true) {
        int temp;
        std::cout << "Enter a temperature: ";
        std::cin >> temp;
        // chech if temp is a number
        if (std::cin.fail()) {
            std::cout << "Invalid input" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        TemperatureConverter t(temp);
        t.setTemp(temp);
        char choice;
        std::cout << "Convert to (C)elcius or (F)ahrenheit? ";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (choice == 'c') {
            std::cout << temp << " Fahrenheit is " << t.FahtoCel() << " Celcius." << std::endl;
        } else if (choice == 'f') {
            std::cout << temp << " Celcius is " << t.CeltoFah() << " Fahrenheit." << std::endl;
        } else {
            std::cout << "Invalid choice" << std::endl;
        }

        char again;
        std::cout << "Do you want to perform another conversion? (y/n) ";
        std::cin >> again;
        if (again == 'n') {
            break;
        }
    }
    return 0;
}