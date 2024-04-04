#include <iostream>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string name, int number, double initialBalance) {
        accountHolderName = name;
        accountNumber = number;
        balance = initialBalance;
    }

    // Deposit money into the account
    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. Current balance: $" << fixed << setprecision(2) << balance << endl;
    }

    // Withdraw money from the account
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds. Withdrawal failed." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. Current balance: $" << fixed << setprecision(2) << balance << endl;
        }
    }

    // Get the current balance
    double getBalance() {
        return balance;
    }
};

int main() {
    // Creating a bank account
    BankAccount myAccount("John Doe", 123456, 12000.00);

    int choice;
    double amount;

    do {
        // Display menu
        cout << "\nBanking Menu:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "0. Exit" << endl;

        // Get user choice
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the deposit amount: $";
                cin >> amount;
                myAccount.deposit(amount);
                break;
            case 2:
                cout << "Enter the withdrawal amount: $";
                cin >> amount;
                myAccount.withdraw(amount);
                break;
            case 3:
                cout << "Current balance: $" << fixed << setprecision(2) << myAccount.getBalance() << endl;
                break;
            case 0:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 0);

    return 0;
}
