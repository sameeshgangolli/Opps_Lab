// Experiment 09: Custom Exception Hierarchy in Banking System
#include <iostream>
#include <exception>
#include <string>
using namespace std;

// Base custom exception
class BankingException : public exception {
protected:
    string message;

public:
    BankingException(string msg) {
        message = msg;
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Derived exception 1: Insufficient Funds
class InsufficientFundsException : public BankingException {
public:
    InsufficientFundsException()
        : BankingException("Error: Insufficient balance for withdrawal!") {}
};

// Derived exception 2: Negative/Invalid Amount
class InvalidAmountException : public BankingException {
public:
    InvalidAmountException()
        : BankingException("Error: Transaction amount must be positive!") {}
};

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initBal) {
        balance = initBal;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw InvalidAmountException();
        }
        balance += amount;
        cout << "Deposited Rs." << amount << " | Balance: Rs." << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw InvalidAmountException();
        }
        if (amount > balance) {
            throw InsufficientFundsException();
        }
        balance -= amount;
        cout << "Withdrawn Rs." << amount << " | Balance: Rs." << balance << endl;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account(5000.0);
    cout << "Initial Balance: Rs." << account.getBalance() << endl;

    // Test Case 1: Valid Deposit
    try {
        cout << "\nAttempting deposit of Rs.1000..." << endl;
        account.deposit(1000.0);
    } catch (const BankingException& e) {
        cout << "Caught Exception: " << e.what() << endl;
    }

    // Test Case 2: Invalid Deposit
    try {
        cout << "\nAttempting invalid deposit of Rs.-500..." << endl;
        account.deposit(-500.0);
    } catch (const BankingException& e) {
        cout << "Caught Exception: " << e.what() << endl;
    }

    // Test Case 3: Overdrawing
    try {
        cout << "\nAttempting withdrawal of Rs.10000..." << endl;
        account.withdraw(10000.0);
    } catch (const BankingException& e) {
        cout << "Caught Exception: " << e.what() << endl;
    }

    cout << "\nFinal Account Balance: Rs." << account.getBalance() << endl;
    return 0;
}
