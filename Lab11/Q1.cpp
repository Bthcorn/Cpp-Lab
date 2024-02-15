#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

struct Movie
{
    std::string title;
    std::vector<std::string> date;
    std::vector<std::vector<int>> availableSeats;
};

struct Reservation
{
    std::string customerName;
    std::string movieTitle;
    std::string date;
    int round;
    int seat;
};

void displaySchedule(const std::vector<Movie> &movies)
{
    for (auto &movie : movies)
    {
        std::cout << "Movie: " << movie.title << std::endl;
        for (int i = 0; i < movie.date.size(); i++)
        {
            std::cout << "Date: " << movie.date[i]
                      << std::setw(10) << "12:00: " << movie.availableSeats[i][0] << " seats available"
                      << std::setw(10) << "15:00: " << movie.availableSeats[i][1] << " seats available"
                      << std::setw(10) << "18:00: " << movie.availableSeats[i][2] << " seats available"
                      << std::setw(10) << "21:00: " << movie.availableSeats[i][3] << " seats available" << std::endl;
        }
        std::cout << std::endl;
    }
}
void vaidateChoice(int &choice);
void validateSeat(int &seat, const int &seats);
void validateRound(int &round);

Reservation makeReservation(std::vector<Movie> &movies)
{
    // display movies
    displaySchedule(movies);

    int movieChoice, dateChoice, roundChoice, seatChoice;

    std::cout << "Select a movie: " << std::endl;
    std::cout << "1. Poor Things" << std::endl;
    std::cout << "2. Harry Potter" << std::endl;
    std::cout << "3. 4KingsII" << std::endl;

    std::cout << "Enter movie number: ";
    std::cin >> movieChoice;
    vaidateChoice(movieChoice);

    std::cout << "Select a date: " << std::endl;
    std::cout << "1. 2024-03-01" << std::endl;
    std::cout << "2. 2024-03-02" << std::endl;
    std::cout << "3. 2024-03-03" << std::endl;
    std::cout << "Enter date number: ";
    std::cin >> dateChoice;
    vaidateChoice(dateChoice);

    std::cout << "Select a round: " << std::endl;
    std::cout << "1. Round 1 - " << movies[movieChoice - 1].availableSeats[dateChoice - 1][0] << " seats available" << std::endl;
    std::cout << "2. Round 2 - " << movies[movieChoice - 1].availableSeats[dateChoice - 1][0] << " seats available" << std::endl;
    std::cout << "3. Round 3 - " << movies[movieChoice - 1].availableSeats[dateChoice - 1][0] << " seats available" << std::endl;
    std::cout << "4. Round 4 - " << movies[movieChoice - 1].availableSeats[dateChoice - 1][0] << " seats available" << std::endl;
    std::cout << "Enter round number: ";
    std::cin >> roundChoice;
    validateRound(roundChoice);

    std::cout << "Enter the number of seats to reserve: ";
    std::cin >> seatChoice;
    validateSeat(seatChoice, movies[movieChoice - 1].availableSeats[dateChoice - 1][roundChoice - 1]);

    Reservation reservation;
    std::cout << "Enter customer name: ";
    std::cin >> reservation.customerName;
    reservation.movieTitle = movies[movieChoice - 1].title;
    reservation.date = movies[movieChoice - 1].date[dateChoice - 1];
    reservation.round = roundChoice;
    reservation.seat = seatChoice;

    movies[movieChoice - 1].availableSeats[dateChoice - 1][roundChoice - 1] -= seatChoice;
    std::cout << "Successfully reserved " << seatChoice << " seats for " << reservation.customerName << " for " << reservation.movieTitle << " on " << reservation.date << " at round " << reservation.round << std::endl;
    return reservation;
}
void vaidateChoice(int &choice)
{
    while (choice < 1 || choice > 3 || std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Invalid choice. Enter again: ";
        std::cin >> choice;
    }
}

void validateSeat(int &seat, const int &seats)
{
    while (seat < 1 || seat > seats || std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Invalid seat. Enter again: ";
        std::cin >> seat;
    }
}

void validateRound(int &round)
{
    while (round < 1 || round > 4 || std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Invalid round. Enter again: ";
        std::cin >> round;
    }
}

void saveData(const std::vector<Movie> &movies, const std::string &filename)
{
    std::ofstream file(filename, std::ios::out);
    if (file.is_open())
    {
        for (auto &movie : movies)
        {
            file << movie.title << std::endl;
            for (int i = 0; i < movie.date.size(); i++)
            {
                file << movie.date[i] << std::endl;
                for (int j = 0; j < 4; j++)
                {
                    file << movie.availableSeats[i][j] << " ";
                }
                file << std::endl;
            }
        }
        file.close();
    }
    else
    {
        std::cout << "Error opening file" << std::endl;
    }
}

void saveData(const std::vector<Reservation> &Reservation, const std::string &filename)
{
    std::ofstream file(filename, std::ios::out);
    if (file.is_open())
    {
        for (auto &reservation : Reservation)
        {
            file << reservation.customerName << std::endl;
            file << reservation.movieTitle << std::endl;
            file << reservation.date << std::endl;
            file << reservation.round << std::endl;
            file << reservation.seat << std::endl;
        }
        file.close();
    }
    else
    {
        std::cout << "Error opening file" << std::endl;
    }
}

void loadData(std::vector<Movie> &movies, const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            Movie movie;
            movie.title = line;
            for (int i = 0; i < 3; i++)
            {
                std::getline(file, line);
                movie.date.push_back(line);
                std::getline(file, line);
                std::istringstream ss(line);
                std::vector<int> seats;
                int seat;
                while (ss >> seat)
                {
                    seats.push_back(seat);
                }
                movie.availableSeats.push_back(seats);
            }
            movies.push_back(movie);
        }
        file.close();
    }
    else
    {
        std::cout << "Error opening file" << std::endl;
    }
}

void loadData(std::vector<Reservation> &reservations, const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            Reservation reservation;
            reservation.customerName = line;
            std::getline(file, line);
            reservation.movieTitle = line;
            std::getline(file, line);
            reservation.date = line;
            std::getline(file, line);
            reservation.round = std::stoi(line);
            std::getline(file, line);
            reservation.seat = std::stoi(line);
            reservations.push_back(reservation);
        }
        file.close();
    }
    else
    {
        std::cout << "Error opening file" << std::endl;
    }
}

void cancelReservation(std::vector<Movie> &movies, std::vector<Reservation> &reservations)
{
    std::string name;
    std::cout << "Enter customer name: ";
    std::cin >> name;

    for (auto &reservation : reservations)
    {
        if (reservation.customerName == name)
        {
            for (auto &movie : movies)
            {
                if (movie.title == reservation.movieTitle)
                {
                    for (int i = 0; i < movie.date.size(); i++)
                    {
                        if (movie.date[i] == reservation.date)
                        {
                            movie.availableSeats[i][reservation.round - 1] += reservation.seat;
                            std::cout << "Reservation cancelled" << std::endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    std::cout << "Reservation not found" << std::endl;
}

int main()
{
    std::vector<Movie> movies;
    std::vector<Reservation> reservations;

    if (std::ifstream("movies.txt"))
    {
        loadData(movies, "movies.txt");
        loadData(reservations, "reservations.txt");
        std::cout << "Data loaded" << std::endl;
    }
    else
    {
        std::cout << "File not found" << std::endl;
        std::cout << "Creating new file" << std::endl;
        movies.emplace_back(Movie{"Poor_Things", {"2024-03-01", "2024-03-02", "2024-03-02"}, {{10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}}});
        movies.emplace_back(Movie{"Harry_Potter", {"2024-03-01", "2024-03-02", "2024-03-02"}, {{10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}}});
        movies.emplace_back(Movie{"4KingsII", {"2024-03-01", "2024-03-02", "2024-03-02"}, {{10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}}});
    }

    while (true)
    {
        std::cout << "1. View schedule" << std::endl;
        std::cout << "2. Make reservation" << std::endl;
        std::cout << "3. Cancel reservation" << std::endl;
        std::cout << "4. Save data" << std::endl;
        std::cout << "5. Exit" << std::endl;

        std::cout << "Enter choice: ";
        int choice;
        std::cin >> choice;

        while (choice < 1 || choice > 5 || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Invalid choice. Enter again: ";
            std::cin >> choice;
        }

        if (choice == 1)
        {
            displaySchedule(movies);
        }
        else if (choice == 2)
        {
            reservations.push_back(makeReservation(movies));
            std::cout << "Reservation made" << std::endl;
        }
        else if (choice == 5)
        {
            std::cout << "Exiting..." << std::endl;
            break;
        }
        else if (choice == 4)
        {
            saveData(movies, "movies.txt");
            saveData(reservations, "reservations.txt");
        }
        else if (choice == 3)
        {
            cancelReservation(movies, reservations);
        }
    }
}