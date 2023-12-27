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

    public:
        HeartRateMonitor(std::string fname, std::string lname, int year, int month, int day) {
            this->fname = fname;
            this->lname = lname;
            this->year = year;
            this->month = month;
            this->day = day;
        }
        int age;
        const int current_year = 2023;
        const int current_month = 12;
        const int current_day = 28;

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
        
        int getAge() const {
            return age;
        }

        void checkMonth() {
            if ( month > current_month) {
                age = current_year - year - 1;
            } else if (month == current_month) {
                if (day > current_day) {
                    age = current_year - year - 1;
                } else {
                    age = current_year - year;
                }
            } else {
                age = current_year - year;
            }
        }

        void displayInformation() {
            checkMonth();
            int beats = 220 - age;
            int maxBeats = beats * 0.85;
            int minBeats = beats * 0.5;
            std::cout << "----------------------------------------" << std::endl;

            std::cout << "Name: " << fname << " " << lname << std::endl;
            std::cout << "Date of Birth: " << year << "/" << month << "/" << day << std::endl;
            std::cout << "Age: " << age << std::endl;
            std::cout << "Maximum Heart Rate: " << beats << std::endl;
            std::cout << "Target Heart Rate: " << minBeats << " - " << maxBeats << std::endl;
        }


};

int main() {
    std::string fname;
    std::string lname;
    std::string input;
    int year;
    int month;
    int day;

    std::cout << "Enter your first name: ";
    std::getline(std::cin, fname);

    std::cout << "Enter your last name: ";
    std::getline(std::cin, lname);

    std::cout << "Enter your birth year (YYYY): ";
    std::getline(std::cin, input);
    year = std::stoi(input);

    std::cout << "Enter your birth month (MM): ";
    std::getline(std::cin, input);
    month = std::stoi(input);

    std::cout << "Enter your birth day (DD): ";
    std::getline(std::cin, input);
    day = std::stoi(input);

    HeartRateMonitor user(fname, lname, year, month, day);
    user.displayInformation();



    return 0;
}
