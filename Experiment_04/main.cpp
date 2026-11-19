// Experiment 04: Single and Multilevel Inheritance (Person -> Student -> GraduateStudent)
#include <iostream>
#include <string>
using namespace std;

// Base class: Person
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    virtual void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class: Student (Single Inheritance)
class Student : public Person {
protected:
    int rollNo;
    string course;

public:
    Student(string n, int a, int r, string c) : Person(n, a) {
        rollNo = r;
        course = c;
    }

    void display() const override {
        Person::display();
        cout << "Roll No: " << rollNo << ", Course: " << course << endl;
    }
};

// Derived class: GraduateStudent (Multilevel Inheritance)
class GraduateStudent : public Student {
private:
    string researchTopic;
    string supervisor;

public:
    GraduateStudent(string n, int a, int r, string c, string topic, string sup)
        : Student(n, a, r, c) {
        researchTopic = topic;
        supervisor = sup;
    }

    void display() const override {
        Student::display();
        cout << "Research Topic: " << researchTopic
             << ", Supervisor: " << supervisor << endl;
    }
};

int main() {
    cout << "--- 1. Single Inheritance (Person -> Student) ---" << endl;
    Student s1("Rahul Sharma", 20, 101, "B.Tech CSE");
    s1.display();

    cout << "\n--- 2. Multilevel Inheritance (Person -> Student -> GraduateStudent) ---" << endl;
    GraduateStudent g1("Pooja Nair", 24, 502, "M.Tech CSE", "Machine Learning", "Dr. K. Verma");
    g1.display();

    return 0;
}
