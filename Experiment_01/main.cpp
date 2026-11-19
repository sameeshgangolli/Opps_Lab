// Experiment 01: Demonstration of Data Types, Constants, Operators, and I/O in C++
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // 1. Constants and Variables
    const float PI = 3.14159f;
    int rollNo = 101;
    char grade = 'A';
    float marks = 89.5f;
    double fee = 125000.75;
    bool isPassed = true;
    string name = "Atharv";

    cout << "--- Student Information ---" << endl;
    cout << "Constant PI: " << PI << endl;
    cout << "Name: " << name << ", Roll No: " << rollNo << endl;
    cout << "Grade: " << grade << ", Marks: " << marks << endl;
    cout << "Fee Paid: " << fee << ", Status: " << (isPassed ? "Pass" : "Fail") << endl;

    // 2. Arithmetic and Relational Operators
    int a = 15, b = 4;
    cout << "\n--- Arithmetic Operators (a = 15, b = 4) ---" << endl;
    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;
    cout << "a / b = " << (a / b) << endl;
    cout << "a % b = " << (a % b) << endl;

    cout << "\n--- Relational and Logical Operators ---" << endl;
    cout << "(a > b): " << (a > b) << endl;
    cout << "(a == b): " << (a == b) << endl;
    cout << "(a > 10 && b < 10): " << (a > 10 && b < 10) << endl;

    // 3. Bitwise Operators
    cout << "\n--- Bitwise Operators (5 and 3) ---" << endl;
    int p = 5, q = 3; // 5 = 0101, 3 = 0011
    cout << "p & q : " << (p & q) << endl;
    cout << "p | q : " << (p | q) << endl;
    cout << "p ^ q : " << (p ^ q) << endl;
    cout << "p << 1: " << (p << 1) << endl;
    cout << "p >> 1: " << (p >> 1) << endl;

    // 4. Formatted I/O with iomanip
    cout << "\n--- Formatted Output (iomanip) ---" << endl;
    cout << left << setw(10) << "Subject" << right << setw(10) << "Marks" << endl;
    cout << "--------------------" << endl;
    cout << left << setw(10) << "Maths" << right << setw(10) << fixed << setprecision(2) << 92.50 << endl;
    cout << left << setw(10) << "OOPS" << right << setw(10) << fixed << setprecision(2) << 88.75 << endl;

    return 0;
}
