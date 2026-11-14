#include <iostream>
#include <stdexcept>

class Overflow : public std::runtime_error {
public:
    Overflow() : std::runtime_error("Stack Overflow: Cannot push to a full stack.") {}
};

class Underflow : public std::runtime_error {
public:
    Underflow() : std::runtime_error("Stack Underflow: Cannot pop from an empty stack.") {}
};

class Stack {
private:
    static const int MAX = 3;
    int arr[MAX];
    int top;

public:
    Stack() : top(-1) {}

    void push(int value) {
        if (top >= MAX - 1) {
            throw Overflow();
        }
        arr[++top] = value;
    }

    int pop() {
        if (top < 0) {
            throw Underflow();
        }
        return arr[top--];
    }
};

int main() {
    Stack s;

    // Test Overflow
    try {
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40); // Triggers Overflow
    } catch (const Overflow& e) {
        std::cerr << e.what() << "\n";
    }

    // Test Underflow
    try {
        s.pop();
        s.pop();
        s.pop();
        s.pop(); // Triggers Underflow
    } catch (const Underflow& e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
