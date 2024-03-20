#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

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

Reservation makeReservation(std::vector<Movie> &movies);
void displaySchedule(std::vector<Movie> &movies);


void saveData(const std::vector<Movie> &movies, const std::string &filename);
void saveData(const std::vector<Reservation> &reservations, const std::string &filename);
void loadData(std::vector<Movie> &movies, const std::string &filename);
void loadData(std::vector<Reservation> &reservations, const std::string &filename);
void cancelReservation(std::vector<Movie> &movies, std::vector<Reservation> &reservations);

int main()
{
    std::vector<Movie> movies;
    std::vector<Reservation> reservations;

    if (std::ifstream("movie.txt"))
    {
        loadData(movies, "movie.txt");
        loadData(reservations, "reservation.txt");
        std::cout << "Data loaded successfully." << '\n';
    }
    else
    {
        movies.push_back(Movie{"Poor thing", {"2024-03-01", "2024-03-02", "2024-03-03"}, {{10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}}});
        movies.push_back(Movie{"4KingII", {"2024-03-01", "2024-03-02", "2024-03-03"}, {{10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}}});
        movies.push_back(Movie{"Aquaman2", {"2024-03-01", "2024-03-02", "2024-03-03"}, {{10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}}});
    }

    displaySchedule(movies);

    int choice;
    while (true)
    {
        std::cout << "1. View Schedule" << '\n';
        std::cout << "2. Make Reservation" << '\n';
        std::cout << "3. Cancel Reservation" << '\n';
        std::cout << "4. Save data" << '\n';
        std::cout << "5. Exit" << '\n';
        std::cout << "Enter choice: ";
        std::cin >> choice;

        while (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Invalid choice. Please enter again.";
            std::cin >> choice;
        }

        switch (choice)
        {
        case 1:
            displaySchedule(movies);
            break;
        case 2:
            reservations.push_back(makeReservation(movies));
            // std::cout << "Successfully reserved." << '\n';
            break;
        case 3:
            cancelReservation(movies, reservations);
            break;
        case 4:
            saveData(movies, "movie.txt");
            saveData(reservations, "reservation.txt");
            break;
        case 5:
            std::cout << "Exiting...";
            return 0;
            break;
        default:
            std::cout << "Invalid choice. Please enter again.";
            break;
        }
    }
}

void saveData(const std::vector<Movie> &movies, const std::string &filename)
{
    std::ofstream file(filename, std::ios::out);
    if (file.is_open())
    {
        for (auto &movie : movies)
        {
            file << movie.title << '\n';
            for (int i = 0; i != movie.date.size(); ++i)
            {
                file << movie.date[i] << '\n';
                for (int j = 0; i != movie.availableSeats.size(); ++j)
                {
                    file << movie.availableSeats[i][j] << " ";
                }
                file << '\n';
            }
        }
        file.close();
    }
    else
    {
        std::cout << "Error opening the file.";
    }
}

void saveData(const std::vector<Reservation> &reservations, const std::string &filename)
{
    std::ofstream file(filename, std::ios::out);
    if (file.is_open())
    {
        for (auto &reservation : reservations)
        {
            file << reservation.customerName << '\n';
            file << reservation.date << '\n';
            file << reservation.movieTitle << '\n';
            file << reservation.round << '\n';
            file << reservation.seat << '\n';
        }
        file.close();
    }
    else
    {
        std::cout << "Error opening the file.";
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
            for (int i = 0; i < 3; ++i)
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
            reservation.date = line;
            std::getline(file, line);
            reservation.movieTitle = line;
            std::getline(file, line);
            int round = std::stoi(line);
            reservation.round = round;
            std::getline(file, line);
            int seats = std::stoi(line);
            reservation.seat = seats;
            reservations.push_back(reservation);
        }
        file.close();
    }
    else
    {
        std::cout << "Error opening the file.";
    }
}

void cancelReservation(std::vector<Movie> &movies, std::vector<Reservation> &reservations)
{
    std::string name;
    std::cout << "Enter customner name: ";
    std::cin >> name;

    for (auto &reservation : reservations)
    {
        if (reservation.customerName == name)
        {
            for (auto &movie : movies)
            {
                if (movie.title == reservation.movieTitle)
                {
                    for (int i = 0; i != movie.date.size(); ++i)
                    {
                        if (movie.date[i] == reservation.date)
                        {
                            movie.availableSeats[i][reservation.round - 1] += reservation.seat;
                            std::cout << "Reservation canceled successfully.";
                            return;
                        }
                    }
                }
            }
        }
        else
        {
            std::cout << "Reservation not found.";
        }
    }
}

void displaySchedule(std::vector<Movie> &movies)
{
    for (auto &movie : movies)
    {
        std::cout << "Movie: " << movie.title << '\n';
        for (int i = 0; i != movie.date.size(); ++i)
        {
            std::cout << "Date: " << movie.date[i] << std::setw(10) << "12:00: " << movie.availableSeats[i][0] << " seats available" << std::setw(10)
                      << "15:00 " << movie.availableSeats[i][1] << " seats available" << std::setw(10)
                      << "18:00 " << movie.availableSeats[i][2] << " seats available" << std::setw(10)
                      << "21:00 " << movie.availableSeats[i][3] << " seats available" << std::setw(10);
            std::cout << '\n';
        }
        std::cout << '\n';
    }
}

void validateChoice(int &choice)
{

    while (choice < 0 || choice > 3 || std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Invalid choice. Please enter again.";
        std::cin >> choice;
    }
}

void validateRound(int &choice)
{

    while (choice < 0 || choice > 4 || std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Invalid choice. Please enter again.";
        std::cin >> choice;
    }
}

void validateSeat(int seat, const int &seats)
{
    while (seat < 0 || seat > seats || std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Invalid choice. Please enter again.";
        std::cin >> seat;
    }
}

Reservation makeReservation(std::vector<Movie> &movies)
{
    displaySchedule(movies);

    std::cout << '\n';

    int nmovie;
    int date;
    int round;
    int seats;

    std::cout << "Select a movie: " << '\n'
              << "1) Poor Thing" << '\n'
              << "2) 4KingII" << '\n'
              << "3) Aquaman2" << '\n';
    std::cout << "Enter movie number: ";
    std::cin >> nmovie;
    validateChoice(nmovie);

    std::cout << "1) 2024-03-01" << '\n'
              << "2) 2024-03-02" << '\n'
              << "3) 2024-03-03" << '\n';
    std::cout << "Enter date number: ";
    std::cin >> date;
    validateChoice(date);

    std::cout << "Select a round: " << '\n';
    std::cout << "1) Round 1 - " << movies[nmovie - 1].availableSeats[date - 1][0] << " seats left" << '\n';
    std::cout << "2) Round 2 - " << movies[nmovie - 1].availableSeats[date - 1][1] << " seats left" << '\n';
    std::cout << "3) Round 3 - " << movies[nmovie - 1].availableSeats[date - 1][2] << " seats left" << '\n';
    std::cout << "4) Round 4 - " << movies[nmovie - 1].availableSeats[date - 1][3] << " seats left" << '\n';
    std::cout << "Enter round number: ";
    std::cin >> round;
    validateRound(round);

    std::cout << "Enter number of seats to reserve: ";
    std::cin >> seats;
    validateSeat(seats, movies[nmovie - 1].availableSeats[date - 1][round - 1]);

    Reservation reservation;
    std::string name;
    std::cout << "Enter customer name: ";
    std::cin >> name;
    reservation.customerName = name;
    reservation.date = movies[nmovie - 1].date[date - 1];
    reservation.round = round;
    reservation.seat = seats;
    movies[nmovie -1].availableSeats[date - 1][round - 1] -= seats;
    std::cout << "Successfully reserved!";
    return reservation;
}
