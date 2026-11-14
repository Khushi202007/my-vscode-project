#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> freq;
    std::string line;

    std::cout << "Enter a line of text:\n";
    std::getline(std::cin, line);

    std::istringstream stream(line);
    std::string word;

    while (stream >> word) {
        freq[word]++;
    }

    if (freq.empty()) {
        std::cout << "No words entered.\n";
        return 0;
    }

    std::string mostFrequentWord;
    int maxCount = 0;

    std::cout << "\nWord Frequencies:\n";
    for (const auto& pair : freq) {
        std::cout << pair.first << ": " << pair.second << "\n";
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequentWord = pair.first;
        }
    }

    std::cout << "\nMost frequent word: \"" << mostFrequentWord 
              << "\" (" << maxCount << " times)\n";

    return 0;
}
