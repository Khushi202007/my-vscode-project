#include <iostream>
#include <string>

class Account {
protected:
    std::string holderName;
    double balance;

public:
    Account(const std::string& name, double initialBalance)
        : holderName(name), balance(initialBalance) {}

    virtual ~Account() = default;

    // Pure virtual function
    virtual double calculateInterest() const = 0;

    virtual void display() const {
        std::cout << holderName << " | Balance: $" << balance
                  << " | Interest: $" << calculateInterest() << "\n";
    }
};

class Savings : public Account {
private:
    static constexpr double RATE = 0.04; // 4% annual interest

public:
    Savings(const std::string& name, double initialBalance)
        : Account(name, initialBalance) {}

    double calculateInterest() const override {
        return balance * RATE;
    }

    void display() const override {
        std::cout << "[Savings] ";
        Account::display();
    }
};

class Current : public Account {
private:
    static constexpr double RATE = 0.01; // 1% annual interest

public:
    Current(const std::string& name, double initialBalance)
        : Account(name, initialBalance) {}

    double calculateInterest() const override {
        return balance * RATE;
    }

    void display() const override {
        std::cout << "[Current] ";
        Account::display();
    }
};

int main() {
    const int SIZE = 3;
    Account* accounts[SIZE];

    accounts[0] = new Savings("Alice", 5000.0);
    accounts[1] = new Current("Bob", 10000.0);
    accounts[2] = new Savings("Charlie", 2500.0);

    for (int i = 0; i < SIZE; i++) {
        accounts[i]->display();
    }

    for (int i = 0; i < SIZE; i++) {
        delete accounts[i];
    }

    return 0;
}
