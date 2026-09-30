#include <iostream>
#include <algorithm> // Required for std::swap
#include <stdexcept>  // Required for std::out_of_range

class Matrix {
private:
    int rows;
    int cols;
    int** data; // Pointer to a 2D array (array of pointers)

    // Secure, exception-safe allocation function
    void allocate(int r, int c) {
        rows = r;
        cols = c;
        data = new int*[rows];
        
        // Initialize all row pointers to nullptr first.
        // This ensures safe cleanup if an exception happens halfway through.
        for (int i = 0; i < rows; ++i) {
            data[i] = nullptr;
        }

        try {
            for (int i = 0; i < rows; ++i) {
                data[i] = new int[cols](); // Initialize grid elements to 0
            }
        } catch (...) {
            // Clean up elements that successfully allocated before the failure
            deallocate();
            throw; // Re-throw the exception to alert the system
        }
    }

    void deallocate() {
        if (data != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i]; // Safe to delete even if it's nullptr
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
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Overloaded Copy Assignment Operator (Copy-and-Swap Idiom)
    // Fixes the double-free crash when running statements like A = B;
    Matrix& operator=(Matrix other) {
        std::swap(rows, other.rows);
        std::swap(cols, other.cols);
        std::swap(data, other.data);
        return *this;
    }

    // Destructor
    ~Matrix() {
        deallocate();
    }

    // Getter function with bounds checking
    int& at(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw std::out_of_range("Matrix index out of bounds");
        }
        return data[r][c];
    }

    // Const Getter function for read-only instances
    int at(int r, int c) const {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw std::out_of_range("Matrix index out of bounds");
        }
        return data[r][c];
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

int main() {
    std::cout << "--- Creating Matrix A (2x3) ---\n";
    Matrix matA(2, 3);
    
    // Assign values using our new safe .at() helper
    matA.at(0, 0) = 1; matA.at(0, 1) = 2; matA.at(0, 2) = 3;
    matA.at(1, 0) = 4; matA.at(1, 1) = 5; matA.at(1, 2) = 6;
    matA.print();

    std::cout << "\n--- Deep Copying A into Matrix B (Copy Constructor) ---\n";
    Matrix matB = matA; 
    matB.print();

    std::cout << "\n--- Modifying Matrix B (Should not affect A) ---\n";
    matB.at(0, 0) = 99;
    std::cout << "Matrix A:\n";
    matA.print();
    std::cout << "Matrix B:\n";
    matB.print();

    std::cout << "\n--- Creating Matrix C (3x2) and Assigning A to it ---\n";
    Matrix matC(3, 2);
    matC = matA; // Overloaded assignment operator safely triggers here
    matC.print();

    return 0;
}
