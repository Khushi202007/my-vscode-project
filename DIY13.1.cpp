#include <iostream>
#include <memory>
#include <string>

class Student {
private:
    std::string name;
    int score;

public:
    Student(std::string n = "", int s = 0) : name(n), score(s) {
        std::cout << "Constructed Student: " << name << "\n";
    }
    ~Student() {
        std::cout << "Destroyed Student: " << name << "\n";
    }
    void display() const {
        std::cout << name << " -> " << score << "\n";
    }
};

int main() {
    // 1. Single object managed by unique_ptr (replaces: Student* s = new Student(...))
    std::unique_ptr<Student> singleStudent = std::make_unique<Student>("Alice", 95);
    singleStudent->display();

    // 2. Dynamic array managed by unique_ptr (replaces: int* arr = new int[n])
    int n = 4;
    std::unique_ptr<int[]> grades = std::make_unique<int[]>(n);

    for (int i = 0; i < n; i++) {
        grades[i] = (i + 1) * 20;
    }

    std::cout << "Grades array: ";
    for (int i = 0; i < n; i++) {
        std::cout << grades[i] << " ";
    }
    std::cout << "\n";

    // No delete or delete[] needed! Memory is cleaned up automatically here.
    return 0;
}
