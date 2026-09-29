#include <iostream>
#include <algorithm>

class Matrix {
private:
    int rows;
    int cols;
    int** data; // Pointer to a 2D array (array of pointers)

    void allocate(int r, int c) {
        rows = r;
        cols = c;
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols](); // Initialize grid elements to 0
        }
    }

    void deallocate() {
        if (data != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i]; // Delete each row
            }
            delete[] data; // Delete array of row pointers
            data = nullptr;
        }
    }

public:
    // Constructor
    Matrix(int r, int c) {
        allocate(r, c);
    }

    // Deep Copy Constructor
    Matrix(const Matrix& other) {
        allocate(other.rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j]; // Copy individual values
            }
        }
    }

    // Destructor
    ~Matrix() {
        deallocate();
    }

    // Member function to display the matrix
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};