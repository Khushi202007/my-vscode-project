#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    int id;

public:
    Employee(const std::string& n, int empId) : name(n), id(empId) {}

    void displayBase() const {
        std::cout << "ID: " << id << " | Name: " << name;
    }
};

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(const std::string& n, int empId, int size)
        : Employee(n, empId), teamSize(size) {}

    void display() const {
        displayBase();
        std::cout << " | Role: Manager | Team Size: " << teamSize << "\n";
    }
};

class Engineer : public Employee {
private:
    std::string skill;

public:
    Engineer(const std::string& n, int empId, const std::string& primarySkill)
        : Employee(n, empId), skill(primarySkill) {}

    void display() const {
        displayBase();
        std::cout << " | Role: Engineer | Primary Skill: " << skill << "\n";
    }
};

int main() {
    Manager mgr("Alice", 101, 12);
    Engineer eng("Bob", 102, "C++ Systems");

    mgr.display();
    eng.display();

    return 0;
}
