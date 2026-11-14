#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    std::vector<std::pair<std::string, int>> items = {
        {"Charlie", 85},
        {"Alice", 92},
        {"Bob", 78},
        {"Diana", 95}
    };

    // Sort by the integer (second) field in ascending order
    std::sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    std::cout << "Sorted pairs (ascending by score):\n";
    for (const auto& p : items) {
        std::cout << p.first << ": " << p.second << "\n";
    }

    return 0;
}
