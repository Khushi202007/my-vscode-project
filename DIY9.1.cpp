#include <iostream>
#include <stdexcept>
#include <string>

// Custom exception class
class InsufficientFunds : public std::runtime_error {
public:
    InsufficientFunds(const std::string& message) 
        : std::runtime_error(message) {}
};

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    // Throws InsufficientFunds instead of returning false
    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFunds("Withdrawal failed: Insufficient funds.");
        }
        balance -= amount;
        std::cout << "Withdrew: $" << amount << " | New Balance: $" << balance << "\n";
    }

    double getBalance() const { return balance; }
};

int main() {
    BankAccount account(100.0);

    try {
        account.withdraw(40.0);   // Succeeds
        account.withdraw(80.0);   // Throws InsufficientFunds
    } catch (const InsufficientFunds& e) {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }

    return 0;
}
