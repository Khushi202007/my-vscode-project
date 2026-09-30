#include <iostream>
using namespace std;

class Counter {
private:
    static int totalCreated;
    static int currentlyAlive;

public:
    // 1. Standard Constructor
    Counter() {
        totalCreated++;
        currentlyAlive++;
    }

    // 2. Destructor
    ~Counter() {
        currentlyAlive--;
    }

    // ERROR FIX: Disable copying to prevent tracking bypasses
    Counter(const Counter&) = delete;            // Disables copy constructor
    Counter& operator=(const Counter&) = delete; // Disables copy assignment

    // Static tracking functions
    static void showTotalCreated() {
        cout << "Total created: " << totalCreated << endl;
    }

    static void showCurrentlyAlive() {
        cout << "Currently alive: " << currentlyAlive << endl;
    }
};

// Initialize static variables
int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main() {
    cout << "=== Creating Objects ===" << endl;
    Counter c1;
    Counter c2;

    {
        Counter c3;
        cout << "Inside block:" << endl;
        Counter::showTotalCreated();   // Outputs: 3
        Counter::showCurrentlyAlive(); // Outputs: 3
    } // c3 is destroyed here

    cout << "\n=== Outside Block ===" << endl;
    Counter::showTotalCreated();       // Outputs: 3
    Counter::showCurrentlyAlive();     // Outputs: 2

    // Counter c4 = c1; // ERROR: This will now safely fail to compile, 
                        // instead of silently breaking your counts!

    return 0;
}
