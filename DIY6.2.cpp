#include <iostream>
#include <numeric> // For std::gcd
#include <sstream>

class Fraction {
private:
    int num;
    int den;

    // Helper function to simplify the fraction
    void simplify() {
        if (den == 0) {
            // Handle division by zero based on your project requirements
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        
        // Ensure the negative sign stays with the numerator
        if (den < 0) {
            num = -num;
            den = -den;
        }

        int common_divisor = std::gcd(num, den);
        num /= common_divisor;
        den /= common_divisor;
    }

public:
    // Constructor with auto-simplification
    Fraction(int numerator = 0, int denominator = 1) : num(numerator), den(denominator) {
        simplify();
    }

    // Overloaded < operator
    // Compares a/b < c/d by cross-multiplying: a*d < c*b to avoid floating-point issues
    bool operator<(const Fraction& other) const {
        return num * other.den < other.num * den;
    }

    // Friend function for stream extraction (>>)
    friend std::istream& operator>>(std::istream& in, Fraction& frac) {
        int numerator, denominator;
        char slash;

        // Expecting input format: "num/den" or just "num"
        in >> numerator;
        
        // Check if a slash follows (peek next non-whitespace char)
        if (in.peek() == '/') {
            in >> slash >> denominator;
        } else {
            denominator = 1; // Default denominator if none is provided
        }

        if (in) {
            frac.num = numerator;
            frac.den = denominator;
            frac.simplify(); // Re-simplify after taking new input
        }

        return in;
    }

    // Friend function for stream insertion (<<) to easily print and verify
    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
        if (frac.den == 1) {
            out << frac.num;
        } else {
            out << frac.num << "/" << frac.den;
        }
        return out;
    }
};

// Example Usage
int main() {
    // 1. Testing auto-simplification on construction
    Fraction f1(4, 8);   // Simplifies to 1/2
    Fraction f2(-6, -9); // Simplifies to 2/3
    std::cout << "f1: " << f1 << "\n";
    std::cout << "f2: " << f2 << "\n";

    // 2. Testing < operator
    if (f1 < f2) {
        std::cout << f1 << " is less than " << f2 << "\n";
    }

    // 3. Testing >> operator
    Fraction f3;
    std::cout << "Enter a fraction (e.g., 10/25): ";
    if (std::cin >> f3) {
        std::cout << "Simplified input: " << f3 << "\n";
    }

    return 0;
}