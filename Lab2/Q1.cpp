#include <iostream>
#include <string>
int main()
{
    std::cout << "Please enter P1 name: ";
    std::string p1_name;
    std::getline(std::cin, p1_name);
    std::cout << "Please enter P2 name: ";
    std::string p2_name;
    // std::cin >> p2_name;
    std::getline(std::cin, p2_name);
    std::cout << "Player 1: " << p1_name << std::endl;
    std::cout << "Player 2: " << p2_name << std::endl;
    return 0;
}