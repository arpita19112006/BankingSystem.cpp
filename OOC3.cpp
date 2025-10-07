#include <iostream>
using namespace std;
class Account {
protected:
    string name;
    int accNumber;
    double balance;
public:
    Account(string n, int a, double b) {
        name = n;
        accNumber = a;
        balance = b;
    }
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }
    void withdraw(double amount) {
        if (amount > balance)
            cout << "Insufficient balance" << endl;
        else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }
    void showStatement() {
        cout << "\nAccount Holder: " << name << endl;
        cout << "Account Number: " << accNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};
class SavingsAccount : public Account {
public:
    SavingsAccount(string n, int a, double b) : Account(n, a, b) {}

    void addInterest() {
        double interest = balance * 0.05;
        balance += interest;
        cout << "Interest added: " << interest << endl;
    }
};
class CheckingAccount : public Account {
public:
    CheckingAccount(string n, int a, double b) : Account(n, a, b) {}

    void deductFee() {
        double fee = 50; 
        balance -= fee;
        cout << "Monthly fee deducted: " << fee << endl;
    }
};
int main() {
    SavingsAccount s1("A", 101, 5000);
    CheckingAccount c1("B", 102, 3000);

    cout << "\nSavings Account" << endl;
    s1.deposit(1000);
    s1.addInterest();
    s1.withdraw(2000);
    s1.showStatement();

    cout << "\nChecking Account " << endl;
    c1.deposit(500);
    c1.deductFee();
    c1.withdraw(1000);
    c1.showStatement();
     return 0;
}