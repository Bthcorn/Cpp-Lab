#include <iostream>
#include "Album1.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Album> albums;
    albums.emplace_back("Abbey Road", "The Beatles", 19.99, 5);
    albums.emplace_back("The Dark Side of the Moon", "Pink Floyd", 21.99, 3);
    albums.emplace_back("Hotel California", "Eagles", 15.99, 4);
    albums.emplace_back("Back in Black", "AC/DC", 20.99, 2);
    albums.emplace_back("Rumours", "Fleetwood Mac", 16.99, 3);
    albums.emplace_back("Thriller", "Michael Jackson", 18.99, 5);
    albums.emplace_back("The Wall", "Pink Floyd", 22.99, 2);
    albums.emplace_back("Led Zeppelin IV", "Led Zeppelin", 17.99, 3);

    while(true) {
        std::cout << "Online Music Store Menu: " << '\n';
        std::cout << "1. List all albums" << '\n';
        std::cout << "2. Purchase an album" << '\n';
        std::cout << "3. Display sales statistics" << '\n';
        std::cout << "4. Exit" << '\n';

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Available Albums:" << '\n';
                for (int i = 0; i < albums.size(); i++) {
                    std::cout << i + 1 << ". " << albums[i].getTitle() << " by " << albums[i].getArtist() << " - " << "$" << albums[i].getPrice() << " (" << albums[i].getCopies() << " copies available)" << '\n';
                }
                std::cout << '\n';
                break;
            case 2:
                int albumNum;
                std::cout << "Enter a number of albums: ";
                std::cin >> albumNum;
                if (albumNum > albums.size() || albumNum < 0 || std::cin.fail() ) {
                    std::cout << "Invalid number." << '\n';
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                } else {
                    albums[albumNum - 1].purchaseAlbum();
                    std::cout << "Successfully purchased!" << '\n';
                }
                break;
            case 3:
                std::cout << "Total albums in inventory: " << Album::getTotalAlbum() << '\n';
                std::cout << "Total sales made: " << Album::getTotalSales() << '\n';
                std::cout << '\n';
                break;
            case 4:
                std::cout << "Exit..." << '\n';
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << '\n';
        }
    }
}