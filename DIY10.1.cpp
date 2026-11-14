#include <iostream>
#include <fstream>
#include <limits>

int main() {
    std::ifstream inFile("nums.txt");
    if (!inFile) {
        std::cerr << "Error: Could not open nums.txt\n";
        return 1;
    }

    int num;
    int count = 0;
    long long sum = 0;
    int minVal = std::numeric_limits<int>::max();
    int maxVal = std::numeric_limits<int>::min();

    while (inFile >> num) {
        count++;
        sum += num;
        if (num < minVal) minVal = num;
        if (num > maxVal) maxVal = num;
    }

    inFile.close();

    if (count == 0) {
        std::cout << "The file is empty or contains no valid integers.\n";
    } else {
        std::cout << "Count: " << count << "\n";
        std::cout << "Sum:   " << sum << "\n";
        std::cout << "Min:   " << minVal << "\n";
        std::cout << "Max:   " << maxVal << "\n";
    }

    return 0;
}
