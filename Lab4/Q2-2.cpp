#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <typeinfo>

class Book
{
private:
    std::string title;
    std::string author;
    int quantity;

public:
    std::string getTitle() const
    {
        return title;
    }

    std::string getAuthor() const
    {
        return author;
    }

    int getQuantity() const
    {
        return quantity;
    }

    void setTitle(const std::string &t)
    {
        title = t;
    }

    void setAuthor(const std::string &a)
    {
        author = a;
    }

    void setQuantity(int q)
    {
        quantity = q;
    }
};

class Inventory
{
public:
    std::vector<Book> books;

    void addBook(const Book &b)
    {
        books.push_back(b);
    }

    void removeBook(const std::string &title)
    {
        // for (auto it = books.begin(); it != books.end(); ++it)
        // {
        //     if (it->getTitle() == title)
        //     {
        //         books.erase(it);
        //         break;
        //     }
        // } or 

        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getTitle() == title)
            {
                books.erase(books.begin() + i);
                break;
            }
        }
    }

    void printInventory() const
    {
        for (const auto &book : books)
        {
            std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor()
                      << ", Quantity: " << book.getQuantity() << std::endl;
        }
    }

    void findBook(const std::string &title) const
    {
        for (const auto &book : books)
        {
            if (book.getTitle() == title)
            {
                std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor()
                          << ", Quantity: " << book.getQuantity() << std::endl;
                return;
            }
        }
        std::cout << "Book not found." << std::endl;
    }
};

int main()
{
    Inventory inv;
    std::string title;
    std::string author;
    int quantity;

    while (true)
    {
        std::cout << "Enter a command (a: Add, s: Search, l: List, r: Remove, q: Quit): ";

        char command;
        std::cin >> command;

        if (command == 'q')
        {
            break;
        }
        else if (command == 'a')
        {
            Book b;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character left in the buffer

            std::cout << "Enter title: ";
            std::getline(std::cin, title);
            b.setTitle(title);
            // std::cin.ignore(1000, '\n'); // Clear the newline character left in the buffer

            std::cout << "Enter author: ";
            std::getline(std::cin, author);
            b.setAuthor(author);
            // std::cin.ignore(1000, '\n'); // Clear the newline character left in the buffer

            std::string userInput;
            std::cout << "Enter quantity: ";
            std::cin >> userInput;

            try
            {
                size_t pos;
                int quantity = std::stoi(userInput, &pos);

                if (pos < userInput.size())
                {
                    std::cout << "Invalid input: Please enter a whole number for quantity.\n";
                }
                else
                {
                    std::cout << "You entered an integer: " << quantity << "\n";
                    b.setQuantity(quantity);
                    inv.addBook(b);
                }
                // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            }
            catch (std::invalid_argument const &e)
            {
                std::cerr << "Invalid input: " << e.what() << "\n";
            }
            catch (std::out_of_range const &e)
            {
                std::cerr << "Invalid input: " << e.what() << "\n";
            }
            // if (std::cin.fail() || quantity.type() != int)
            // {
            //     std::cout << "Invalid input. Please enter a whole number for quantity." << std::endl;
            //     std::cin.clear();                                                   // Clear error flags
            //     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            //     continue;
            // }
        }
        else if (command == 's')
        {
            std::cout << "Enter title: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character left in the buffer
            std::string title;
            std::getline(std::cin, title);
            inv.findBook(title);
        }
        else if (command == 'l')
        {
            if (inv.books.empty())
            {
                std::cout << "Inventory is empty." << std::endl;
            }
            else
            {
                inv.printInventory();
            }
        }
        else if (command == 'r')
        {
            std::cout << "Enter title: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character left in the buffer
            std::string title;
            std::getline(std::cin, title);
            inv.removeBook(title);
        }
        else
        {
            std::cout << "Invalid command" << std::endl;
        }

        std::cin.clear(); // Clear any remaining error flags
    }

    return 0;
}
