#include <iostream>
#include <stdexcept>

template <typename T>
void swapVals(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T findMax(T arr[], int n) {
    if (n <= 0) {
        throw std::invalid_argument("Array size must be greater than zero.");
    }
    T maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    // Testing with int
    int x = 10, y = 25;
    std::cout << "Before swap (int): x = " << x << ", y = " << y << "\n";
    swapVals(x, y);
    std::cout << "After swap (int):  x = " << x << ", y = " << y << "\n";

    int intArr[] = {14, 72, 39, 91, 53};
    std::cout << "Max in intArr: " << findMax(intArr, 5) << "\n\n";

    // Testing with double
    double d1 = 3.14, d2 = 9.81;
    std::cout << "Before swap (double): d1 = " << d1 << ", d2 = " << d2 << "\n";
    swapVals(d1, d2);
    std::cout << "After swap (double):  d1 = " << d1 << ", d2 = " << d2 << "\n";

    double doubleArr[] = {2.5, 8.9, 1.2, 6.7};
    std::cout << "Max in doubleArr: " << findMax(doubleArr, 4) << "\n";

    return 0;
}
