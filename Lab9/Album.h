#ifndef ALBUM_H
#define ALBUM_H
#include <string>

class Album
{
private:
    std::string title;
    std::string artist;
    double price;
    int copies;
    static double totalSales;
public:
    static int totalAlbums;
    Album(const std::string& title, const std::string& artist, double price, int copies);
    std::string getTitle() const;
    std::string getArtist() const;
    double getPrice();
    int getCopies();
    void purchaseAlbum();
    static int getTotalAlbum();
    static double getTotalSales();
};

#endif