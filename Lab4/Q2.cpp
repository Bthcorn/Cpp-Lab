#include <iostream>
#include <vector>
#include <string>
#include <limits>

class Book {
    private:
        std::string title;
        std::string author;
        int quantity;

    public:
        std::string getTitle() {
            return title;
        }
        
        std::string getAuthor() {
            return author;
        }

        int getQuantity() {
            return quantity;
        }

        void setTitle(std::string t) {
            title = t;
        }

        void setAuthor(std::string a) {
            author = a;
        }

        void setQuantity(int q) {
            quantity = q;
        }
};

class Inventory {
    public:
        std::vector<Book> books;
        void addBook(Book b) {
            books.push_back(b);
        }

        void removeBook(std::string title) {
            for (int i = 0; i < books.size(); i++) {
                if (books[i].getTitle() == title) {
                    books.erase(books.begin() + i);
                }
            }
        }

        void printInventory() {
            for (int i = 0; i < books.size(); i++) {
                std::cout << "Title: " << books[i].getTitle() << ", " << "Author: " << books[i].getAuthor() << ", " << "Quantity: " << books[i].getQuantity() << std::endl;
            }
        }

        void findBook(std::string title) {
            for (int i = 0; i < books.size(); i++) {
                if (books[i].getTitle() == title) {
                    std::cout << books[i].getTitle() << " " << books[i].getAuthor() << " " << books[i].getQuantity() << std::endl;
                }
            }
        }
};

int main() {

    Inventory inv;

    while(true) {
        std::cout << "Enter a commnad (a: Add, s: Search, l: List, r: Remove, q: Quit): ";

        char command;
        std::cin >> command;

        if (command == 'q') {
            break;
        } else if (command = 'a') {
           Book b;

            std::cout << "Enter title: ";
            std::string title;
            std::getline(std::cin, title);
            b.setTitle(title);
            std::cin.ignore();
            // std::cin.clear();

            std::cout << "Enter author: ";
            std::string author;
            std::getline(std::cin, author);
            b.setAuthor(author);
            std::cin.ignore();

            int quantity;
            std::cout << "Enter quantity: ";
            std::cin >> quantity;
            b.setQuantity(quantity);

            // if (std::cin.fail()) {
            //     std::cout << "Invalid input" << std::endl;
            //     std::cin.clear();
            //     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //     continue;
            // } else {
            //     b.setQuantity(quantity);
            // }

            inv.addBook(b);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        } else if (command == 's') {
            std::cout << "Enter title: ";
            std::string title;
            std::getline(std::cin, title);
            std::cin.clear();
            std::cin.ignore();
            inv.findBook(title);

        } else if (command == 'l') {
            if (inv.books.size() == 0) {
                continue;
            } else {
                inv.printInventory();
            }
        } else if (command == 'r') {
            std::cout << "Enter title: ";
            std::string title;
            std::getline(std::cin, title);
            inv.removeBook(title);
            std::cin.clear();
            std::cin.ignore();
        } else {
            std::cout << "Invalid command" << std::endl;
        }
        std::cin.clear();
        // std::cin.ignore(1000, '\n');
        // std::cin.ignore();
    }
}

