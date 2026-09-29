#include <iostream>

class Tracer {
public:
    Tracer() { std::cout << "Tracer created\n"; }
    ~Tracer() { std::cout << "Tracer destroyed\n"; }
};

int main() {
    for (int i = 0; i < 5; ++i) {
        // Intentionally allocating on the heap and forgetting delete
        Tracer* t = new Tracer();
        // delete t; // Omitted to trigger a memory leak
    }
    return 0;
}