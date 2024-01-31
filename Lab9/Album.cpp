#include "Album.h"
#include <iostream>
#include <stdexcept>

int Album::totalAlbums = 0; 
double Album::totalSales = 0;

Album::Album(const std::string& title, const std::string& artist, double price, int copies) : title(title), artist(artist), price(price), copies(copies)
{
    totalAlbums += copies;
    // totalSales += price * copies;
}

std::string Album::getTitle() const
{
    return title;
}

std::string Album::getArtist() const
{
    return artist;
}

double Album::getPrice()
{
    return price;
}

int Album::getCopies()
{
    return copies;
}

void Album::purchaseAlbum()
{
    // if (num > copies)
    // {
    //     std::cout << "Not enough copies" << std::endl;
    // }
    if (copies > 0) 
    {
        copies -= 1;
        totalSales += price;
    } 
    else 
    {
        throw std::invalid_argument("Not enough copies!");
    }
}

int Album::getTotalAlbum()
{
    return totalAlbums;
}

double Album::getTotalSales()
{
    return totalSales;
}