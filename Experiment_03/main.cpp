// Experiment 03: Constructor Types (Default, Parameterized, Copy, Move) and Rule of 5
#include <iostream>
#include <utility>
using namespace std;

class ArrayHandler {
private:
    int* arr;
    int size;

public:
    // 1. Default Constructor
    ArrayHandler() {
        size = 0;
        arr = nullptr;
        cout << "Default constructor called" << endl;
    }

    // 2. Parameterized Constructor
    ArrayHandler(int s, int val) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = val + i;
        }
        cout << "Parameterized constructor called (size = " << size << ")" << endl;
    }

    // 3. Copy Constructor (Deep Copy)
    ArrayHandler(const ArrayHandler& other) {
        size = other.size;
        if (other.arr != nullptr) {
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        } else {
            arr = nullptr;
        }
        cout << "Copy constructor called (Deep Copy)" << endl;
    }

    // 4. Move Constructor
    ArrayHandler(ArrayHandler&& other) noexcept {
        size = other.size;
        arr = other.arr; // steal resource
        other.arr = nullptr;
        other.size = 0;
        cout << "Move constructor called" << endl;
    }

    // 5. Copy Assignment Operator
    ArrayHandler& operator=(const ArrayHandler& other) {
        if (this != &other) {
            delete[] arr; // free existing memory
            size = other.size;
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }
        cout << "Copy assignment operator called" << endl;
        return *this;
    }

    // 6. Move Assignment Operator
    ArrayHandler& operator=(ArrayHandler&& other) noexcept {
        if (this != &other) {
            delete[] arr;
            size = other.size;
            arr = other.arr;
            other.arr = nullptr;
            other.size = 0;
        }
        cout << "Move assignment operator called" << endl;
        return *this;
    }

    // 7. Destructor
    ~ArrayHandler() {
        delete[] arr;
        cout << "Destructor called (Memory freed)" << endl;
    }

    void display() const {
        if (size == 0 || arr == nullptr) {
            cout << "Array is empty" << endl;
            return;
        }
        cout << "Elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "--- 1. Creating Objects ---" << endl;
    ArrayHandler a1; // default
    ArrayHandler a2(4, 10); // parameterized
    a2.display();

    cout << "\n--- 2. Copy Constructor ---" << endl;
    ArrayHandler a3 = a2; // copy
    a3.display();

    cout << "\n--- 3. Move Constructor ---" << endl;
    ArrayHandler a4 = move(a3); // move
    a4.display();

    cout << "\n--- 4. Assignment Operators ---" << endl;
    ArrayHandler a5;
    a5 = a2; // copy assignment
    a5.display();

    ArrayHandler a6;
    a6 = move(a4); // move assignment
    a6.display();

    cout << "\n--- End of Program (Destructors will be invoked) ---" << endl;
    return 0;
}
