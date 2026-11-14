#include <iostream>
#include <mutex>
#include <thread>

int sharedCounter = 0;
std::mutex mtx;

// 1. Unsafe function without lock_guard (causes data race)
void incrementUnsafe(int iterations) {
    for (int i = 0; i < iterations; i++) {
        sharedCounter++; // Not atomic: read-modify-write overlaps across threads
    }
}

// 2. Thread-safe function with lock_guard
void incrementSafe(int iterations) {
    for (int i = 0; i < iterations; i++) {
        std::lock_guard<std::mutex> lock(mtx);
        sharedCounter++;
    }
}

int main() {
    const int ITERATIONS = 100000;

    // --- Part A: Without lock_guard (observe wrong total) ---
    sharedCounter = 0;
    std::thread t1(incrementUnsafe, ITERATIONS);
    std::thread t2(incrementUnsafe, ITERATIONS);
    t1.join();
    t2.join();
    std::cout << "Without lock_guard (Expected 200000): " << sharedCounter << "\n";

    // --- Part B: With lock_guard (always 200000) ---
    sharedCounter = 0;
    std::thread t3(incrementSafe, ITERATIONS);
    std::thread t4(incrementSafe, ITERATIONS);
    t3.join();
    t4.join();
    std::cout << "With lock_guard    (Expected 200000): " << sharedCounter << "\n";

    return 0;
}
