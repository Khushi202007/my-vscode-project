// Program 9.3 – Exception class hierarchy (a base catch catches derived)

#include <iostream>
#include <exception>
using namespace std;
struct NetworkError : exception {
    const char* what() const noexcept override { return "network error"; }
};
struct TimeoutError : NetworkError {             // IS-A NetworkError
    const char* what() const noexcept override { return "timeout"; }
};
void fetch(int ms) {
    if (ms > 100) throw TimeoutError();
    cout << "fetched in " << ms << " ms\n";
}
int main() {
    for (int d : {50, 200}) {
        try { fetch(d); }
        catch (const NetworkError &e) {        // base catch also catches derived
            cout << "caught: " << e.what() << endl;
        }
    }
    return 0;
}