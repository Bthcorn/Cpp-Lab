#include <algorithm>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

struct Movie {
  std::string title;
  std::vector<std::string> date;
  std::vector<std::vector<int>> availableSeats;
};

struct Reservation {
  std::string movie;
  std::string date;
  int round;
  int seat;
  std::string name;
};

void initMovie(std::vector<Movie> &movie);

// ANCHOR - Display and Reservation
void displaySchedule(const std::vector<Movie> &movie);
Reservation makeReservation(std::vector<Movie> &movie);
void cancelReservation(std::vector<Movie> &movie,
                       std::vector<Reservation> &reserv);

// ANCHOR - Save and Load Data
void saveData(const std::vector<Movie> &movies, const std::string &filename);
void saveData(const std::vector<Reservation> &reserv,
              const std::string &filename);
void loadData(std::vector<Reservation> &reserv, const std::string &filename);
void loadData(std::vector<Movie> &movies, const std::string &filename);

int main() {
  std::vector<Movie> movie;
  std::vector<Reservation> reserv;
  if (std::ifstream("movie.txt")) {
    loadData(movie, "movie.txt");
  } else {
    initMovie(movie);
  }
  if (std::ifstream("reservation.txt")) {
    loadData(reserv, "reservation.txt");
  } else {
    reserv = {};
  }

  while (true) {
    int choice;
    std::cout << "1. View schedule\n2. Make reservation\n3. Cancle\n4. "
                 "SaveFile\n5. Quit\nEnter your choice: ";
    while (true) {
      if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Invalid input. Please enter a number: ";
      } else if (choice < 1 || choice > 5) {
        std::cout << "Invalid input. Please enter a number between 1 and 5: ";
      } else {
        break;
      }
    }
    if (choice == 1) {
      displaySchedule(movie);
    } else if (choice == 2) {
      reserv.push_back(makeReservation(movie));
    } else if (choice == 3) {
      cancelReservation(movie, reserv);
    } else if (choice == 4) {
      saveData(movie, "movie.txt");
      saveData(reserv, "reservation.txt");
    } else if (choice == 5) {
      break;
    }
  }
  return 0;
}

void initMovie(std::vector<Movie> &movie) {
  /// to use .availableSeats[dayIndex][roundIndex] to access the available seats
  /// in that round
  Movie m1 = {"Poor Things",
              {"2024-03-01", "2024-03-02", "2024-03-03"},
              {{10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}}};
  Movie m2 = {"HAMER",
              {"2024-03-01", "2024-03-02", "2024-03-03"},
              {{10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}}};

  Movie m3 = {"4KingsII",
              {"2024-03-01", "2024-03-02", "2024-03-03"},
              {{10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}}};

  movie.push_back(m1);
  movie.push_back(m2);
  movie.push_back(m3);
}

void displaySchedule(const std::vector<Movie> &movie) {
  for (auto &m : movie) {
    std::cout << "Movie: " << m.title << std::endl;
    for (int d = 0; d < m.date.size(); d++) {
      std::cout << " Date: " << m.date[d] << "\t";
      for (int r = 0; r < m.availableSeats[d].size(); r++) {
        if (r == 0) {
          std::cout << "12:00: " << m.availableSeats[d][r]
                    << " seats available\t";
        } else if (r == 1) {
          std::cout << "15:00: " << m.availableSeats[d][r]
                    << " seats available\t";
        } else if (r == 2) {
          std::cout << "18:00: " << m.availableSeats[d][r]
                    << " seats available\t";
        } else {
          std::cout << "21:00: " << m.availableSeats[d][r]
                    << " seats available\t";
        }
      }
      std::cout << std::endl;
    }
  }
}

Reservation makeReservation(std::vector<Movie> &movie) {
  std::string name;
  int dateIndex;
  int movieIndex;
  int roundIndex;
  int seatMany;
  std::cout << "Select a movie:\n1)Poor Things\n2)HAMER\n3)4KingsII\nEnter "
               "movie number: ";

  while (true) {
    if (!(std::cin >> movieIndex)) {
      std::cin.clear();
      std::cin.ignore(100, '\n');
      std::cout << "Invalid input. Please enter a number: ";
    }
    if (movieIndex < 1 || movieIndex > 3) {
      std::cout << "Invalid input. Please enter a number between 1 and 3: ";
    } else {
      break;
    }
  }

  std::cout << "Select a date:\n1)2024-03-01\n2)2024-03-02\n3)2024-03-03\n"
               "Enter date number: ";

  while (true) {
    if (!(std::cin >> dateIndex)) {
      std::cin.clear();
      std::cin.ignore(100, '\n');
      std::cout << "Invalid input. Please enter a number: ";
    } else if (dateIndex < 1 || dateIndex > 3) {
      std::cout << "Invalid input. Please enter a number between 1 and 3: ";
    } else {
      break;
    }
  }

  std::cout << "Select a round:\n1)Round 1 - "
            << movie[movieIndex - 1].availableSeats[dateIndex - 1][0]
            << " seats available\n2)Round 2 - "
            << movie[movieIndex - 1].availableSeats[dateIndex - 1][1]
            << " seats available\n3)Round 3 - "
            << movie[movieIndex - 1].availableSeats[dateIndex - 1][2]
            << " seats available\n4)Round 4 - "
            << movie[movieIndex - 1].availableSeats[dateIndex - 1][3]
            << " seats available\nEnter round number: ";

  while (true) {
    if (!(std::cin >> roundIndex)) {
      std::cin.clear();
      std::cin.ignore(100, '\n');
      std::cout << "Invalid input. Please enter a number: ";
    } else if (roundIndex < 1 || roundIndex > 4) {
      std::cout << "Invalid input. Please enter a number between 1 and 4: ";
    } else {
      break;
    }
  }

  std::cout << "Enter seat you want to reserv: ";

  while (true) {
    if (!(std::cin >> seatMany)) {
      std::cin.clear();
      std::cin.ignore(100, '\n');
      std::cout << "Invalid input. Please enter a number: ";
    } else if (seatMany < 1 ||
               seatMany > movie[movieIndex - 1]
                              .availableSeats[dateIndex - 1][roundIndex - 1]) {
      std::cout
          << "Invalid input. Please enter a number between 1 and "
          << movie[movieIndex - 1].availableSeats[dateIndex - 1][roundIndex - 1]
          << ": ";
    } else {
      break;
    }
  }
  while (true) {
    std::cout << "Enter your name: ";
    std::cin >> name;
    if (name.size() > 0) {
      break;
    } else {
      std::cout << "Invalid input. Please enter a name: ";
    }
  }

  std::cout << "Successfully reserved " << seatMany << " seats for "
            << movie[movieIndex - 1].title << " on "
            << movie[movieIndex - 1].date[dateIndex - 1] << " at round "

            << roundIndex << std::endl;

  movie[movieIndex - 1].availableSeats[dateIndex - 1][roundIndex - 1] -=
      seatMany;

  Reservation r = {movie[movieIndex - 1].title,
                   movie[movieIndex - 1].date[dateIndex - 1], roundIndex,
                   seatMany, name};
  return r;
}

void cancelReservation(std::vector<Movie> &movie,
                       std::vector<Reservation> &reserv) {
  std::string name;
  std::cout << "Enter your name: ";
  std::cin >> name;
  for (int i = 0; i < reserv.size(); i++) {
    if (reserv[i].name == name) {
      for (int j = 0; j < movie.size(); j++) {
        if (reserv[i].movie == movie[j].title) {
          for (int k = 0; k < movie[j].date.size(); k++) {
            if (reserv[i].date == movie[j].date[k]) {
              movie[j].availableSeats[k][reserv[i].round - 1] += reserv[i].seat;
              reserv.erase(reserv.begin() + i);
              std::cout << "Successfully canceled reservation" << std::endl;
              return;
            }
          }
        }
      }
    }
  }
  std::cout << "No reservation found" << std::endl;
}

void saveData(const std::vector<Movie> &movies, const std::string &filename) {
  std::ofstream file(filename);
  if (file.is_open()) {
    for (auto &m : movies) {
      file << m.title << std::endl;
      for (int d = 0; d < m.date.size(); d++) {
        file << m.date[d] << "\t";
        for (int r = 0; r < m.availableSeats[d].size(); r++) {
          file << m.availableSeats[d][r] << " ";
        }
        file << std::endl;
      }
    }
    file.close();
  } else {
    std::cout << "Unable to open file" << std::endl;
  }
}

void saveData(const std::vector<Reservation> &reserv,
              const std::string &filename) {
  std::ofstream file(filename);
  if (file.is_open()) {
    for (auto &r : reserv) {
      file << r.movie << std::endl;
      file << r.date << std::endl;
      file << r.round << std::endl;
      file << r.seat << std::endl;
      file << r.name << std::endl;
    }
    file.close();
  } else {
    std::cout << "Unable to open file" << std::endl;
  }
}

void loadData(std::vector<Movie> &movies, const std::string &filename) {
  std::ifstream file(filename);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      Movie m;
      m.title = line;
      for (int i = 0; i < 3; i++) {
        std::getline(file, line);
        std::string date = line.substr(0, 10);
        m.date.push_back(date);
        std::vector<int> seats;
        std::string seat = line.substr(11, line.size());
        std::string delimiter = " ";
        size_t pos = 0;
        std::string token;
        while ((pos = seat.find(delimiter)) != std::string::npos) {
          token = seat.substr(0, pos);
          seats.push_back(std::stoi(token));
          seat.erase(0, pos + delimiter.length());
        }
        m.availableSeats.push_back(seats);
      }
      movies.push_back(m);
    }
    file.close();
  } else {
    std::cout << "Unable to open file" << std::endl;
  }
  return;
}

void loadData(std::vector<Reservation> &reserv, const std::string &filename) {
  std::ifstream file(filename);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      Reservation r;
      r.movie = line;
      std::getline(file, line);
      r.date = line;
      std::getline(file, line);
      r.round = std::stoi(line);
      std::getline(file, line);
      r.seat = std::stoi(line);
      std::getline(file, line);
      r.name = line;
      reserv.push_back(r);
    }
    file.close();
  } else {
    std::cout << "Unable to open file" << std::endl;
  }
  return;
}