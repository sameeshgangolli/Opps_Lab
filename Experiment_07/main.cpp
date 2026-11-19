// Experiment 07: Generic Stack Class using Templates
#include <iostream>
#include <string>
using namespace std;

#define MAX 50

template <class T>
class Stack {
private:
    T arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isFull() const {
        return top == MAX - 1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    void push(T val) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push." << endl;
            return;
        }
        arr[++top] = val;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Stack is empty." << endl;
            return T();
        }
        return arr[top--];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "--- 1. Testing Stack with int ---" << endl;
    Stack<int> sInt;
    sInt.push(10);
    sInt.push(20);
    sInt.push(30);
    sInt.display();
    cout << "Popped: " << sInt.pop() << endl;
    sInt.display();

    cout << "\n--- 2. Testing Stack with float ---" << endl;
    Stack<float> sFloat;
    sFloat.push(1.5f);
    sFloat.push(3.14f);
    sFloat.push(9.8f);
    sFloat.display();
    cout << "Popped: " << sFloat.pop() << endl;
    sFloat.display();

    cout << "\n--- 3. Testing Stack with string ---" << endl;
    Stack<string> sString;
    sString.push("Pune");
    sString.push("Mumbai");
    sString.push("Delhi");
    sString.display();
    cout << "Popped: " << sString.pop() << endl;
    sString.display();

    return 0;
}
