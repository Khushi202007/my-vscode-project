#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n;
    std::cout << "Enter count of numbers (N): ";
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "Invalid count.\n";
        return 1;
    }

    // Min-heap to keep track of the top 3 largest elements
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    std::cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        int val;
        std::cin >> val;
        minHeap.push(val);

        // If heap grows beyond 3 elements, remove the smallest one
        if (minHeap.size() > 3) {
            minHeap.pop();
        }
    }

    // Extract elements from min-heap (smallest to largest of the top 3)
    std::vector<int> topThree;
    while (!minHeap.empty()) {
        topThree.push_back(minHeap.top());
        minHeap.pop();
    }

    std::cout << "Top " << topThree.size() << " largest numbers: ";
    for (int i = static_cast<int>(topThree.size()) - 1; i >= 0; i--) {
        std::cout << topThree[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
