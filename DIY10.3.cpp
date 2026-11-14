#include <iostream>
#include <fstream>
#include <string>

class Student {
public:
    std::string name;
    double marks;

    Student() : name(""), marks(0.0) {}
    Student(std::string n, double m) : name(n), marks(m) {}
};

int main() {
    const std::string filename = "students.txt";

    // Step 1: Write name and marks pairs to the file
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error: Could not open file for writing.\n";
        return 1;
    }
    outFile << "Alice 88.5\n";
    outFile << "Bob 95.0\n";
    outFile << "Charlie 91.2\n";
    outFile << "Diana 97.8\n";
    outFile.close();

    // Step 2: Read records back into an array of Student objects
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error: Could not open file for reading.\n";
        return 1;
    }

    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int count = 0;

    std::string tempName;
    double tempMarks;

    while (count < MAX_STUDENTS && (inFile >> tempName >> tempMarks)) {
        students[count] = Student(tempName, tempMarks);
        count++;
    }
    inFile.close();

    // Step 3: Find and print the topper
    if (count == 0) {
        std::cout << "No student records found.\n";
        return 0;
    }

    int topperIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].marks > students[topperIndex].marks) {
            topperIndex = i;
        }
    }

    std::cout << "Topper: " << students[topperIndex].name 
              << " with " << students[topperIndex].marks << " marks.\n";

    return 0;
}
