// Experiment 08: Demonstration of STL Containers and Algorithms
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {
    // 1. Vector of Student records
    vector<Student> students = {
        {101, "Atharv", 88.5f},
        {104, "Rohan",  72.0f},
        {102, "Sneha",  95.0f},
        {103, "Pooja",  81.5f}
    };

    cout << "--- 1. Original Student Records (vector) ---" << endl;
    for (const auto& s : students) {
        cout << "Roll: " << s.rollNo << ", Name: " << s.name << ", Marks: " << s.marks << endl;
    }

    // 2. Algorithm: sort students by marks in descending order
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.marks > b.marks;
    });

    cout << "\n--- 2. Students Sorted by Marks (Descending) ---" << endl;
    for (const auto& s : students) {
        cout << "Roll: " << s.rollNo << ", Name: " << s.name << ", Marks: " << s.marks << endl;
    }

    // 3. Algorithm: find_if to find student with marks >= 90
    auto it = find_if(students.begin(), students.end(), [](const Student& s) {
        return s.marks >= 90.0f;
    });
    if (it != students.end()) {
        cout << "\nTop Performer (Marks >= 90): " << it->name << " (" << it->marks << ")" << endl;
    }

    // 4. Map (Ordered by Roll No)
    map<int, string> studentMap;
    for (const auto& s : students) {
        studentMap[s.rollNo] = s.name;
    }

    cout << "\n--- 3. Student Map (Ordered by Roll Number) ---" << endl;
    for (const auto& p : studentMap) {
        cout << "Roll No: " << p.first << " -> Name: " << p.second << endl;
    }

    // 5. Unordered Map (Hash table for fast lookup)
    unordered_map<string, float> marksMap;
    for (const auto& s : students) {
        marksMap[s.name] = s.marks;
    }

    cout << "\n--- 4. Unordered Map Lookup ---" << endl;
    cout << "Marks for Atharv: " << marksMap["Atharv"] << endl;
    cout << "Marks for Sneha : " << marksMap["Sneha"] << endl;

    return 0;
}
