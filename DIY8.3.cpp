#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor\n";
    }

    // BUG: Non-virtual destructor causes Derived destructor to be skipped!
    // FIX: Uncomment 'virtual' below to prevent the memory leak:
    // virtual
    ~Base() {
        std::cout << "Base destructor\n";
    }
};

class Derived : public Base {
private:
    int* data;

public:
    Derived() {
        data = new int[100];
        std::cout << "Derived constructor (allocated 100 ints)\n";
    }

    ~Derived() {
        delete[] data;
        std::cout << "Derived destructor (freed 100 ints)\n";
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr; // Only calls ~Base() unless ~Base() is virtual

    return 0;
}
