#ifndef ALBUM_H1
#define ALBUM_H1

#include <string>

class Album 
{
private:
    std::string title;
    std::string artist;
    double price;
    int copiesAvailable;
public:
    static int totalAlbums;
    static double totalSales;
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