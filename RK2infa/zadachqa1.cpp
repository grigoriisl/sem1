#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string ownerName;
    double balance;
public:
    BankAccount(string accNum, string name, double initialBalance)
        : accountNumber(accNum), ownerName(name), balance(initialBalance) {}
    
    void deposit(double amount) {
        balance += amount;
    }
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        }
    }
    void display() {
        cout << "ID аккаунта: " << accountNumber << ", Владелец: " << ownerName 
             << ", Баланс: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double percentRate;
public:
    SavingsAccount(string accNum, string name, double initialBalance, double rate)
        : BankAccount(accNum, name, initialBalance), percentRate(rate) {}
    
    void applyPercent() {
        balance += balance * percentRate / 100;
    }
    void display() {
        BankAccount::display();
        cout << "Процентная ставка: " << percentRate << "%" << endl;
    }
};

int main() {
    BankAccount regularAcc("154822", "Максим Стасенко", 1000);
    SavingsAccount savingsAcc("821381", "Цуп Алексей", 2000, 5);
    regularAcc.deposit(6000.2);
    regularAcc.withdraw(230.1);
    regularAcc.display();
    savingsAcc.deposit(1300.0);
    savingsAcc.withdraw(563.5);
    savingsAcc.applyPercent();
    savingsAcc.display();
    return 0;
}