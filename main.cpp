#include <iostream>
#include <string>
#include <vector>

#define MAX_ACCOUNTS 10

// Structure to represent an account
struct Account {
    int accountNumber;
    string pin;
    float balance;
};

vector<Account> accounts; // Using vector instead of an array
int accountCount = 0;

// Function to create a new account
void createAccount(int accountNumber, string pin, float initialBalance) {
    if (accountCount < MAX_ACCOUNTS) {
        Account newAccount;
        newAccount.accountNumber = accountNumber;
        newAccount.pin = pin;
        newAccount.balance = initialBalance;
        accounts.push_back(newAccount);
        accountCount++;
        cout << "Account created successfully!\n";
    } else {
        cout << "Cannot create more accounts. Limit reached.\n";
    }
}

// Function to find an account by account number
int findAccount(int accountNumber) {
    for (int i = 0; i < accountCount; ++i) {
        if (accounts[i].accountNumber == accountNumber) {
            return i; // Return the index of the account if found
        }
    }
    return -1; // Return -1 if account not found
}

// Function to simulate a withdrawal
void withdraw(int accountIndex, float amount) {
    if (accounts[accountIndex].balance >= amount) {
        accounts[accountIndex].balance -= amount;
        cout << "Withdrawal successful. Remaining balance: $" << accounts[accountIndex].balance << endl;
    } else {
        cout << "Insufficient funds!\n";
    }
}

// Function to simulate a deposit
void deposit(int accountIndex, float amount) {
    accounts[accountIndex].balance += amount;
    cout << "Deposit successful. New balance: $" << accounts[accountIndex].balance << endl;
}

// Function to display account balance
void displayBalance(int accountIndex) {
    cout << "Account Number: " << accounts[accountIndex].accountNumber << endl;
    cout << "Current Balance: $" << accounts[accountIndex].balance << endl;
}

int main() {
    // Creating sample accounts
    int acc_no;
    float init_balance;
    string acc_pin;
    cout << "Enter Account Number: ";
    cin >> acc_no;
    cout << "Enter Account Pin: ";
    cin >> acc_pin;
    cout << "Enter Account Starting Balance: ";
    cin >> init_balance;
    createAccount(acc_no, acc_pin, init_balance);

    int choice, accountNumber, accountIndex;
    string pin;
    float amount;

    do {
        cout << "\nWelcome to Mini ATM\n";
        cout << "1. Login\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter PIN: ";
                cin >> pin;

                accountIndex = findAccount(accountNumber);
                if (accountIndex != -1 && accounts[accountIndex].pin == pin) {
                    int option;
                    do {
                        cout << "\n1. Withdraw\n";
                        cout << "2. Deposit\n";
                        cout << "3. Check Balance\n";
                        cout << "4. Logout\n";
                        cout << "Enter option: ";
                        cin >> option;

                        switch (option) {
                            case 1:
                                cout << "Enter amount to withdraw: ";
                                cin >> amount;
                                withdraw(accountIndex, amount);
                                break;
                            case 2:
                                cout << "Enter amount to deposit: ";
                                cin >> amount;
                                deposit(accountIndex, amount);
                                break;
                            case 3:
                                displayBalance(accountIndex);
                                break;
                            case 4:
                                cout << "Logged out.\n";
                                break;
                            default:
                                cout << "Invalid option\n";
                        }
                    } while (option != 4);
                } else {
                    cout << "Invalid account number or PIN\n";
                }
                break;
            case 2:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 2);

    return 0;
}
