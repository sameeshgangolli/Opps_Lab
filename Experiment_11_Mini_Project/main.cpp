// Experiment 11: Mini Project - Student Management System
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    string department;
    float marks;

public:
    Student(int r = 0, string n = "", string dept = "", float m = 0.0f) {
        rollNo = r;
        name = n;
        department = dept;
        marks = m;
    }

    int getRollNo() const { return rollNo; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
    float getMarks() const { return marks; }

    void display() const {
        cout << "Roll No: " << rollNo
             << " | Name: " << name
             << " | Dept: " << department
             << " | Marks: " << marks << endl;
    }

    string toCSV() const {
        return to_string(rollNo) + "," + name + "," + department + "," + to_string(marks);
    }
};

class StudentManager {
private:
    vector<Student> list;
    const string filename = "students_db.csv";

public:
    void addStudent(int roll, string name, string dept, float marks) {
        list.push_back(Student(roll, name, dept, marks));
        cout << "Student added successfully!" << endl;
    }

    void displayAll() const {
        if (list.empty()) {
            cout << "No student records found." << endl;
            return;
        }
        cout << "\n--- Student Records ---" << endl;
        for (const auto& s : list) {
            s.display();
        }
    }

    void searchByRoll(int roll) const {
        for (const auto& s : list) {
            if (s.getRollNo() == roll) {
                cout << "Record Found: ";
                s.display();
                return;
            }
        }
        cout << "Student with Roll No " << roll << " not found." << endl;
    }

    void deleteStudent(int roll) {
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (it->getRollNo() == roll) {
                list.erase(it);
                cout << "Student with Roll No " << roll << " deleted successfully." << endl;
                return;
            }
        }
        cout << "Student with Roll No " << roll << " not found." << endl;
    }

    void saveToFile() const {
        ofstream out(filename);
        if (!out) {
            cout << "Error opening file to save!" << endl;
            return;
        }
        for (const auto& s : list) {
            out << s.toCSV() << "\n";
        }
        out.close();
        cout << "Records saved to " << filename << " successfully." << endl;
    }

    void loadFromFile() {
        ifstream in(filename);
        if (!in) {
            return;
        }
        list.clear();
        string line;
        while (getline(in, line)) {
            if (line.empty()) continue;
            size_t p1 = line.find(',');
            size_t p2 = line.find(',', p1 + 1);
            size_t p3 = line.find(',', p2 + 1);

            int roll = stoi(line.substr(0, p1));
            string name = line.substr(p1 + 1, p2 - p1 - 1);
            string dept = line.substr(p2 + 1, p3 - p2 - 1);
            float marks = stof(line.substr(p3 + 1));

            list.push_back(Student(roll, name, dept, marks));
        }
        in.close();
        cout << "Loaded " << list.size() << " records from file." << endl;
    }
};

int main() {
    StudentManager sm;

    cout << "============================================" << endl;
    cout << "    STUDENT MANAGEMENT SYSTEM (MINI PROJECT) " << endl;
    cout << "============================================" << endl;

    // 1. Adding Sample Students
    cout << "\n1. Adding Students..." << endl;
    sm.addStudent(101, "Atharv Sharma", "CSE", 89.5f);
    sm.addStudent(102, "Sneha Patel", "ECE", 94.0f);
    sm.addStudent(103, "Rohan Verma", "MECH", 76.5f);

    // 2. Display All Students
    cout << "\n2. Displaying All Records:" << endl;
    sm.displayAll();

    // 3. Search Student by Roll No
    cout << "\n3. Searching for Roll No 102:" << endl;
    sm.searchByRoll(102);

    cout << "\n4. Searching for Non-existent Roll No 999:" << endl;
    sm.searchByRoll(999);

    // 4. Save to File
    cout << "\n5. Saving Records to File..." << endl;
    sm.saveToFile();

    // 5. Delete a Student
    cout << "\n6. Deleting Student with Roll No 103:" << endl;
    sm.deleteStudent(103);
    sm.displayAll();

    // 6. Reload from File to verify persistence
    cout << "\n7. Reloading Saved State from File:" << endl;
    sm.loadFromFile();
    sm.displayAll();

    return 0;
}
