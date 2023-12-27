#include <iostream>
#include <string>
#include <sstream>

class HeartRateMonitor {
private:
    std::string fname;
    std::string lname;
    int year;
    int month;
    int day;
    int beats;
    int maxBeats;
    int minBeats;

public:
    int year_old;
    const int current_year = 2023;
    const int current_month = 12;
    const int current_day = 28;

    void setFname(std::string fName) {
        fname = fName;
    }

    void setLname(std::string lName) {
        lname = lName;
    }

    void setYear(int y) {
        year = y;
    }

    void setMonth(int m) {
        month = m;
    }

    void setDay(int d) {
        day = d;
    }

    std::string getFname() const {
        return fname;
    }

    std::string getLname() const {
        return lname;
    }

    int getYear() const {
        return year;
    }

    int getMonth() const {
        return month;
    }

    int getDay() const {
        return day;
    }

    void setYearold() {
        year_old = current_year - year;
    }

    int getBeats() const {
        return beats;
    }

    int getYearold() const {
        return year_old;
    }

    void checkMonth() {
        if (month < current_month) {
            year_old = year_old - 1;
        } else if (month == current_month) {
            if (day < current_day) {
                year_old = year_old - 1;
            }
        }
    }

    void calBeats() {
        beats = 220 - getYearold();
        maxBeats = 0.85 * beats;
        minBeats = 0.50 * beats;
    }

    void displayInformation() {
        calBeats();

        std::cout << "Hello, " << getYearold() << " years old " << getFname() << " " << getLname() << "." << "\n";
        std::cout << "Your maximum heart rate should be " << getBeats() << " beats per minute." << "\n";
        std::cout << "Your target heart rate range is " << minBeats << " - " << maxBeats << " beats per minute." << "\n";
    }
};

int main() {
    std::string firstName;
    std::string lastName;
    int y;
    int m;
    int d;

    std::string input;

    HeartRateMonitor user;
    

    std::cout << "Enter your first name: ";
    std::getline(std::cin, firstName);
    user.setFname(firstName);

    std::cout << "Enter your last name: ";
    std::getline(std::cin, lastName);
    user.setLname(lastName);

    std::cout << "Enter your birth year (YYYY): ";
    std::getline(std::cin, input);
    y = std::stoi(input);
    user.setYear(y);
    // handle if number is valid or not

    std::cout << "Enter your birth month (MM): ";
    std::getline(std::cin, input);
    m = std::stoi(input);
    user.setMonth(m);


    std::cout << "Enter your birth day (DD): ";
    std::getline(std::cin, input);
    d = std::stoi(input);
    user.setDay(d);
    user.setYearold();
    user.checkMonth();
    std::cout << "\n";

    user.displayInformation();

    return 0;
}
