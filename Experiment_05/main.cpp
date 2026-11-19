// Experiment 05: Runtime Polymorphism using Virtual Functions and Abstract Base Class
#include <iostream>
using namespace std;

// Abstract base class
class Shape {
public:
    // Pure virtual function
    virtual double area() const = 0;
    virtual void display() const = 0;

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void display() const override {
        cout << "Circle (Radius = " << radius << ") -> Area: " << area() << endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double area() const override {
        return length * width;
    }

    void display() const override {
        cout << "Rectangle (Length = " << length << ", Width = " << width << ") -> Area: " << area() << endl;
    }
};

// Derived class: Triangle
class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    double area() const override {
        return 0.5 * base * height;
    }

    void display() const override {
        cout << "Triangle (Base = " << base << ", Height = " << height << ") -> Area: " << area() << endl;
    }
};

int main() {
    // Array of base class pointers demonstrating runtime polymorphism
    Shape* shapes[3];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);
    shapes[2] = new Triangle(3.0, 8.0);

    cout << "--- Calculating Areas using Runtime Polymorphism ---" << endl;
    for (int i = 0; i < 3; i++) {
        shapes[i]->display(); // dynamically dispatched call
    }

    // Free memory
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    return 0;
}
