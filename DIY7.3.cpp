#include <iostream>
#include <string>

class Person {
protected:
    std::string name;

public:
    Person(const std::string& n = "Unknown") : name(n) {}

    void showName() const {
        std::cout << "Name: " << name << "\n";
    }
};

class Student : virtual public Person {
protected:
    int studentId;

public:
    Student(const std::string& n, int sId) : Person(n), studentId(sId) {}
};

class Employee : virtual public Person {
protected:
    int employeeId;

public:
    Employee(const std::string& n, int eId) : Person(n), employeeId(eId) {}
};

class TA : public Student, public Employee {
private:
    std::string course;

public:
    // Most-derived class directly initializes the virtual base class Person
    TA(const std::string& n, int sId, int eId, const std::string& c)
        : Person(n), Student(n, sId), Employee(n, eId), course(c) {}

    void displayDetails() const {
        // No ambiguity because only one Person subobject exists
        showName();
        std::cout << "Student ID:  " << studentId << "\n";
        std::cout << "Employee ID: " << employeeId << "\n";
        std::cout << "Assisting:   " << course << "\n";
    }
};

int main() {
    TA ta("Diana", 5001, 9001, "Object-Oriented Programming");
    ta.displayDetails();

    return 0;
}
