#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual std::string name() const = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159265 * radius * radius; }
    std::string name() const override { return "Circle"; }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
    std::string name() const override { return "Rectangle"; }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override { return 0.5 * base * height; }
    std::string name() const override { return "Triangle"; }
};

// Factory function returning a smart pointer
std::unique_ptr<Shape> createShape(const std::string& type) {
    if (type == "circle" || type == "Circle") {
        double r;
        std::cout << "Enter radius: ";
        std::cin >> r;
        return std::make_unique<Circle>(r);
    } else if (type == "rectangle" || type == "Rectangle") {
        double w, h;
        std::cout << "Enter width and height: ";
        std::cin >> w >> h;
        return std::make_unique<Rectangle>(w, h);
    } else if (type == "triangle" || type == "Triangle") {
        double b, h;
        std::cout << "Enter base and height: ";
        std::cin >> b >> h;
        return std::make_unique<Triangle>(b, h);
    }
    return nullptr;
}

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    std::string input;

    std::cout << "Enter shape (circle, rectangle, triangle) or 'done' to finish:\n";
    while (true) {
        std::cout << "> ";
        std::cin >> input;
        if (input == "done") break;

        std::unique_ptr<Shape> s = createShape(input);
        if (s) {
            shapes.push_back(std::move(s));
        } else {
            std::cout << "Unknown shape type. Try again.\n";
        }
    }

    std::cout << "\n--- Created Shapes ---\n";
    for (const auto& s : shapes) {
        std::cout << s->name() << " | Area: " << s->area() << "\n";
    }

    return 0;
}
