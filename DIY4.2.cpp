#include <iostream>
#include <stdexcept>

class Stack {
private:
    int* buffer;      // Pointer to the dynamic array
    int capacity;     // Maximum number of elements the stack can hold
    int topIndex;     // Index of the top element (-1 when empty)

public:
    // Constructor: Allocates memory for the dynamic array
    Stack(int size) {
        if (size <= 0) {
            throw std::invalid_argument("Stack capacity must be greater than zero.");
        }
        capacity = size;
        buffer = new int[capacity];
        topIndex = -1; // Stack starts empty
    }

    // Destructor: Releases the allocated buffer memory
    ~Stack() {
        delete[] buffer;
    }

    // Push: Adds an element to the top of the stack
    void push(int value) {
        if (topIndex >= capacity - 1) {
            throw std::overflow_error("Stack Overflow: Cannot push to a full stack.");
        }
        buffer[++topIndex] = value;
    }

    // Pop: Removes and returns the top element of the stack
    int pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack Underflow: Cannot pop from an empty stack.");
        }
        return buffer[topIndex--];
    }

    // Peek: Returns the top element without removing it
    int peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty. Cannot peek.");
        }
        return buffer[topIndex];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return topIndex == -1;
    }

    // Get the current number of elements
    int size() const {
        return topIndex + 1;
    }
};

int main() {
    try {
        // Instantiate a stack with a capacity of 3
        Stack myStack(3);

        myStack.push(10);
        myStack.push(20);
        myStack.push(30);

        std::cout << "Top element is: " << myStack.peek() << std::endl;

        std::cout << "Popped: " << myStack.pop() << std::endl;
        std::cout << "Popped: " << myStack.pop() << std::endl;

        // The destructor executes automatically when myStack goes out of scope here
    } 
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}