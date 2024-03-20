#include "Album1.h"
#include <iostream>

double Album::totalSales = 0;
int Album::totalAlbums = 0;

Album::Album(const std::string& title, const std::string& artist, double price, int copies) : title(title), artist(artist), price(price), copiesAvailable(copies) {
    totalAlbums += copies;
}

std::string Album::getTitle() const {
    return title;
}

std::string Album::getArtist() const {
    return artist;
}

double Album::getPrice() {
    return price;
}

int Album::getCopies() {
    return copiesAvailable;
}

void Album::purchaseAlbum() {
    if (copiesAvailable > 0) {
        totalAlbums -= 1;
        copiesAvailable -= 1;
        totalSales += price;
    } else {
        std::cout << "Ran out of copies." << '\n';
    }
}

int Album::getTotalAlbum() {
    return totalAlbums;
}

double Album::getTotalSales() {
    return totalSales;
}