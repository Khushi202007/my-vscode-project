#include <iostream>
#include <string>

class Shape {
protected:
    std::string color;

public:
    Shape(const std::string& c) : color(c) {
        std::cout << "1. Shape constructor called (color = " << color << ")\n";
    }
};

class Polygon : public Shape {
protected:
    int numSides;

public:
    Polygon(const std::string& c, int sides) : Shape(c), numSides(sides) {
        std::cout << "2. Polygon constructor called (numSides = " << numSides << ")\n";
    }
};

class Rectangle : public Polygon {
private:
    double area;

public:
    Rectangle(const std::string& c, double width, double height)
        : Polygon(c, 4), area(width * height) {
        std::cout << "3. Rectangle constructor called (area = " << area << ")\n";
    }

    void printSummary() const {
        std::cout << "\nSummary -> Color: " << color
                  << ", Sides: " << numSides
                  << ", Area: " << area << "\n";
    }
};

int main() {
    Rectangle rect("Blue", 5.0, 4.0);
    rect.printSummary();

    return 0;
}
