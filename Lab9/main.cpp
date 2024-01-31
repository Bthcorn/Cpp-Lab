#include <iostream>
#include <vector>
#include <stdexcept>
#include "Album.h"

int main()
{
    std::vector<Album> albums;
    albums.emplace_back("Abbey Road", "The Beatles", 19.99, 5);
    albums.emplace_back("The Dark Side of the Moon", "Pink Floyd", 21.99, 3);
    albums.emplace_back("Hotel California", "Eagles", 15.99, 4);
    albums.emplace_back("Back in Black", "AC/DC", 20.99, 2);
    albums.emplace_back("Rumours", "Fleetwood Mac", 16.99, 3);
    albums.emplace_back("Thriller", "Michael Jackson", 18.99, 5);
    albums.emplace_back("The Wall", "Pink Floyd", 22.99, 2);
    albums.emplace_back("Led Zeppelin IV", "Led Zeppelin", 17.99, 3);

    while (true)
    {
        std::cout << std::endl;

        std::cout << "Online Music Store Menu" << std::endl;
        std::cout << "1. List all albums" << std::endl;
        std::cout << "2. Purchase an album" << std::endl;
        std::cout << "3. Purchase all albums" << std::endl;
        std::cout << "4. Display sales statistics" << std::endl;
        std::cout << "5. Exit" << std::endl;

        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        try
        {

            if (choice == 1)
            {
                std::cout << "Albums in the store:" << std::endl;
                for (int i = 0; i < albums.size(); i++)
                {
                    std::cout << i + 1 << ". " << albums[i].getTitle() << " by " << albums[i].getArtist() << " $" << albums[i].getPrice() << " "
                              << "available: " << albums[i].getCopies() << std::endl;
                }
            }
            else if (choice == 2)
            {
                std::cout << "Enter the album number you wish to purchase: ";
                int albumNum;
                std::cin >> albumNum;
                if (albumNum > albums.size() || albumNum < 1)
                {
                    throw std::invalid_argument("Invalid album number. Please try again.");
                }
                else
                {
                    Album::totalAlbums -= 1;
                    albums[albumNum - 1].purchaseAlbum();
                }
            }
            else if (choice == 3)
            {
                for (int i = 0; i < albums.size(); i++)
                {
                    albums[i].purchaseAlbum();
                }
                Album::totalAlbums -= albums.size();
            }
            else if (choice == 4)
            {
                std::cout << "Total number of albums in the store: " << Album::getTotalAlbum() << std::endl;
                std::cout << "Total sales: $" << Album::getTotalSales() << std::endl;
            }
            else if (choice == 5)
            {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            else
            {
                throw std::invalid_argument("Invalid choice. Please try again.");
            }
        }
        catch (std::invalid_argument e)
        {
            std::cout << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        std::cout << std::endl;
    }
}