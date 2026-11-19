// Experiment 06: Compile-Time Polymorphism (Function and Operator Overloading)
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructors
    Complex(double r = 0.0, double i = 0.0) {
        real = r;
        imag = i;
    }

    // 1. Function Overloading
    void add(double r) {
        real += r;
    }

    void add(double r, double i) {
        real += r;
        imag += i;
    }

    void add(const Complex& c) {
        real += c.real;
        imag += c.imag;
    }

    // 2. Operator Overloading: Binary '+'
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Operator Overloading: Binary '-'
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Operator Overloading: Binary '*'
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }

    // Operator Overloading: Stream Insertion '<<'
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0)
            out << " + " << c.imag << "i";
        else
            out << " - " << -c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    cout << "\n--- Function Overloading ---" << endl;
    Complex c3 = c1;
    c3.add(5.0); // adds scalar real
    cout << "c1 after add(5.0): " << c3 << endl;

    c3.add(1.0, 2.0); // adds real and imaginary
    cout << "c1 after add(1.0, 2.0): " << c3 << endl;

    cout << "\n--- Operator Overloading ---" << endl;
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;

    cout << "c1 + c2 = " << sum << endl;
    cout << "c1 - c2 = " << diff << endl;
    cout << "c1 * c2 = " << prod << endl;

    return 0;
}
