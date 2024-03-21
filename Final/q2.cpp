#include <iostream>
#include <array>
#include <stdexcept>

class Matrix
{
private:
    const size_t rows;
    const size_t cols;
    std::array<std::array<int, 100>, 100> matrix; // Assuming maximum size is 100x100

public:
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
        // No need for resizing as we're using std::array
        // matrix.resize(rows, std::array<int, 100>(cols, 0));
    }

    void set(size_t row, size_t col, int value) {
        if (row >= rows || col >= cols) {
            throw std::out_of_range("Index out of bounds");
        }
        matrix[row][col] = value;
    }

    size_t getRow() const {
        return rows;
    }

    size_t getCol() const {
        return cols;
    }

    int get(size_t row, size_t col) const {
        if (row >= rows || col >= cols) {
            throw std::out_of_range("Index out of bounds");
        }
        return matrix[row][col];
    }

    void print() const {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix operator+(const Matrix& m) const {
        if (rows != m.rows || cols != m.cols) {
            throw std::invalid_argument("Error: Matrices are not of same size");
        }
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                result.set(i, j, matrix[i][j] + m.get(i, j));
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& m) const {
        if (rows != m.rows || cols != m.cols) {
            throw std::invalid_argument("Error: Matrices are not of same size");
        }
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                result.set(i, j, matrix[i][j] - m.get(i, j));
            }
        }
        return result;
    }
};
