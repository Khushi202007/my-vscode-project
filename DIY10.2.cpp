#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile("in.txt");
    if (!inFile) {
        std::cerr << "Error: Could not open in.txt\n";
        return 1;
    }

    std::ofstream outFile("out.txt");
    if (!outFile) {
        std::cerr << "Error: Could not create out.txt\n";
        return 1;
    }

    std::string line;
    int lineNumber = 1;

    while (std::getline(inFile, line)) {
        outFile << lineNumber << ": " << line << "\n";
        lineNumber++;
    }

    inFile.close();
    outFile.close();

    std::cout << "Successfully copied lines to out.txt\n";
    return 0;
}
