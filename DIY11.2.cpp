#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class Queue {
private:
    static const int CAPACITY = 100;
    T data[CAPACITY];
    int frontIdx;
    int rearIdx;
    int count;

public:
    Queue() : frontIdx(0), rearIdx(-1), count(0) {}

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == CAPACITY;
    }

    void enqueue(const T& item) {
        if (isFull()) {
            throw std::overflow_error("Queue Overflow: Cannot enqueue into a full queue.");
        }
        rearIdx = (rearIdx + 1) % CAPACITY;
        data[rearIdx] = item;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue Underflow: Cannot dequeue from an empty queue.");
        }
        frontIdx = (frontIdx + 1) % CAPACITY;
        count--;
    }

    T front() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty: No front element.");
        }
        return data[frontIdx];
    }
};

int main() {
    Queue<std::string> q;

    q.enqueue("Alice");
    q.enqueue("Bob");
    q.enqueue("Charlie");

    std::cout << "Front element: " << q.front() << "\n";
    q.dequeue();

    std::cout << "Front after one dequeue: " << q.front() << "\n";
    q.dequeue();

    std::cout << "Front after two dequeues: " << q.front() << "\n";
    q.dequeue();

    return 0;
}
