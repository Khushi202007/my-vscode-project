#include <fstream>
#include <iostream>
#include <string>

class Logger {
public:
    virtual ~Logger() = default;
    virtual void write(const std::string& message) = 0;
};

class ConsoleLogger : public Logger {
public:
    void write(const std::string& message) override {
        std::cout << "[Console] " << message << "\n";
    }
};

class FileLogger : public Logger {
private:
    std::ofstream outFile;

public:
    FileLogger(const std::string& filename) {
        outFile.open(filename, std::ios::app);
    }

    ~FileLogger() override {
        if (outFile.is_open()) {
            outFile.close();
        }
    }

    void write(const std::string& message) override {
        if (outFile.is_open()) {
            outFile << "[File] " << message << "\n";
            std::cout << "(Logged message to file)\n";
        } else {
            std::cerr << "Error: Could not write to log file.\n";
        }
    }
};

int main() {
    ConsoleLogger consoleLog;
    FileLogger fileLog("app.log");

    // Start with ConsoleLogger
    Logger* activeLogger = &consoleLog;
    activeLogger->write("System initialized.");

    // Switch logger at runtime based on user choice
    int choice;
    std::cout << "Choose logger (1 = Console, 2 = File): ";
    std::cin >> choice;

    if (choice == 2) {
        activeLogger = &fileLog;
    } else {
        activeLogger = &consoleLog;
    }

    activeLogger->write("User action recorded.");

    return 0;
}
