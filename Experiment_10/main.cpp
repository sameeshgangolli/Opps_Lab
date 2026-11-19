// Experiment 10: File Handling - CSV Reader/Writer and Stream Positioning
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {
    const string filename = "students.csv";

    // 1. Writing records to CSV and demonstrating tellp()
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    cout << "Initial write pointer position (tellp): " << outFile.tellp() << endl;

    outFile << "Roll,Name,Marks\n";
    cout << "Position after header (tellp): " << outFile.tellp() << endl;

    outFile << "101,Atharv,88.5\n";
    outFile << "102,Sneha,92.0\n";
    outFile << "103,Rohan,76.5\n";

    cout << "Position after writing 3 records (tellp): " << outFile.tellp() << endl;
    outFile.close();

    // 2. Reading records from CSV and demonstrating tellg() and seekg()
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nInitial read pointer position (tellg): " << inFile.tellg() << endl;

    string line;
    cout << "\n--- Student Records Read from CSV ---" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    cout << "End-of-file read pointer position (tellg): " << inFile.tellg() << endl;

    // 3. Demonstrating seekg() to rewind back to start
    inFile.clear(); // clear EOF flag
    inFile.seekg(0, ios::beg);
    cout << "\nAfter seekg(0, ios::beg), pointer is at: " << inFile.tellg() << endl;

    getline(inFile, line);
    cout << "Re-reading line 1: " << line << endl;

    inFile.close();
    return 0;
}
