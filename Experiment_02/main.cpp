// Experiment 02: Real-World Class Hierarchy, Access Specifiers, and Member Functions
#include <iostream>
#include <string>
using namespace std;

// Base class
class BankAccount {
private:
    int accountNumber;
    int pin; // private to this class only

protected:
    string accountHolder;
    double balance; // accessible in derived classes

public:
    // Parameterized constructor
    BankAccount(int accNo, string name, double initialBalance, int p) {
        accountNumber = accNo;
        accountHolder = name;
        balance = initialBalance;
        pin = p;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: Rs." << amount << " | New Balance: Rs." << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance! Available: Rs." << balance << endl;
        } else if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: Rs." << amount << " | Remaining Balance: Rs." << balance << endl;
        }
    }

    void display() const {
        cout << "Account No: " << accountNumber
             << ", Holder: " << accountHolder
             << ", Balance: Rs." << balance << endl;
    }
};

// Derived class
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double initialBalance, int p, double rate)
        : BankAccount(accNo, name, initialBalance, p) {
        interestRate = rate;
    }

    void addInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest of Rs." << interest << " added at " << interestRate << "%." << endl;
    }
};

int main() {
    SavingsAccount acc(1001, "Atharv Sharma", 5000.0, 1234, 4.0);

    cout << "--- Initial Account Details ---" << endl;
    acc.display();

    cout << "\n--- Performing Transactions ---" << endl;
    acc.deposit(1500.0);
    acc.withdraw(2000.0);
    acc.withdraw(10000.0); // test insufficient balance
    acc.addInterest();

    cout << "\n--- Final Account Details ---" << endl;
    acc.display();

    return 0;
}
