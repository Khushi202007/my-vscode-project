#include <iostream>
#include <stdexcept>
#include <string>

// Base exception class
class MathError : public std::runtime_error {
public:
    MathError(const std::string& msg) : std::runtime_error(msg) {}
};

// Derived exception class
class DivideByZero : public MathError {
public:
    DivideByZero() : MathError("Division by zero is undefined.") {}
};

double divide(double a, double b) {
    if (b == 0) {
        throw DivideByZero();
    }
    return a / b;
}

int main() {
    // 1. DEMONSTRATING THE ISSUE (Uncomment to see compiler warning/error)
    /*
    try {
        divide(10, 0);
    } catch (const MathError& e) {
        // Because DivideByZero IS-A MathError, this block catches it first
        std::cout << "Caught MathError: " << e.what() << "\n";
    } catch (const DivideByZero& e) {
        // Dead code: the compiler flags this as hidden/unreachable
        std::cout << "Caught DivideByZero: " << e.what() << "\n";
    }
    */

    // 2. FIXED ORDER: Derived class first, Base class second
    try {
        divide(10, 0);
    } catch (const DivideByZero& e) {
        std::cout << "Caught DivideByZero: " << e.what() << "\n";
    } catch (const MathError& e) {
        std::cout << "Caught MathError: " << e.what() << "\n";
    }

    return 0;
}
