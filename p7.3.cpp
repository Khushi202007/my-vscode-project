//Program 7.3 – Hierarchical inheritance & protected access
#include <iostream>
using namespace std;
class Account {
protected:                              // visible to derived, hidden from outside
    double balance = 0;
public:
    void deposit(double a) { balance += a; }
    double get() const { return balance; }
};
class Savings : public Account {       // hierarchical: both derive from Account
public:
    void addInterest() { balance *= 1.04; }   // reaches protected 'balance'
};
class Current : public Account {
public:
    void charge(double fee) { balance -= fee; }
};
int main() {
    Savings s; s.deposit(1000); s.addInterest();
    Current c; c.deposit(1000); c.charge(50);
    cout << "Savings = " << s.get() << ", Current = " << c.get() << endl;
    return 0;
}



//Public: Accessible inside its own class, in derived classes, and from outside the class.
//Protected: Accessible inside its own class and derived classes, but not directly from outside the class.
//Private: Accessible only inside its own class, not directly in derived classes or from outside the class.