#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

class Account {

private:
    string name;
    long long accountNumber;
    string pin;
    double balance;

public:
    void createAccount();
    void deposit(double amount);
    void withdraw(double amount);
    void checkBalance();
    void showDetails();

    long long getAccountNumber();
    string getpin();
};

void Account::createAccount() {

    system("cls");
    cout << "---------------------------------\n";
    cout << "          CREATE ACCOUNT\n";
    cout << "---------------------------------\n";

    cout << "Enter Full Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    cout << "Enter 4-Digit PIN: ";
    cin >> pin;

    while (pin.length() != 4 || !isdigit(pin[0]) || !isdigit(pin[1]) || !isdigit(pin[2]) || !isdigit(pin[3])) {
        cout << "Invalid PIN! Enter again: ";
        cin >> pin;
    }

    cout << "Minimum Deposit (Rs. 500+): ";
    cin >> balance;

    while (balance < 500) {
        cout << "Minimum deposit is 500. Enter again: ";
        cin >> balance;
    }
    system("cls");
    cout << "\nAccount Created Successfully.\n";
}

void Account::deposit(double amount) {

    cout << "---------------------------------\n";
    if (amount <= 0) {
        cout << "Invalid Deposit Amount\n";
    } else {
        balance += amount;
        system("cls");
        cout << "Amount Deposited Successfully\n";
        cout << "Current Balance: Rs. " << balance;
    }
}

void Account::withdraw(double amount) {

    cout << "---------------------------------\n";
    if (amount <= 0) {
        cout << "Invalid Withdrawal Amount\n";
    } 
    else if (amount > balance) {
        system("cls");
        cout << "Insufficient Balance\n";
        cout << "Current Balance: Rs. " << balance;
    } 
    else {
        balance -= amount;
        system("cls");
        cout << "Withdrawal Successful\n";
        cout << "Current Balance: Rs. " << balance;
    }
}

void Account::checkBalance() {
    system("cls");
    cout << "Current Balance: Rs. " << balance << endl;
}

void Account::showDetails() {
    system("cls");
    cout << "---------------------------------\n";
    cout << "Name: " << name << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: Rs. " << balance << endl;
}

long long Account::getAccountNumber() {
    return accountNumber;
}

string Account::getpin() {
    return pin;
}

\
class BankSystem {

private:
    vector<Account> accounts;
    int userIndex;

public:
    BankSystem();
    void run();
    void showMainMenu();
    void login();
    void createAccount();
    void showAccountMenu();
};

BankSystem::BankSystem() {
    userIndex = -1;
}

void BankSystem::run() {

    int choice;
    do {
        showMainMenu();
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: login(); 
                    if (userIndex != -1) showAccountMenu();
                    break;
            case 3:
                system("cls");
                cout << "\nThank You for Banking with Us\n";
                cout<< "EXITING";
                Sleep(500); cout << ".";
                Sleep(500); cout << ".";
                Sleep(500); cout << ".\n";
                break;
            default:
                cout << "Invalid Choice. Try Again.\n";
        }

    } while (choice != 3);
}

void BankSystem::showMainMenu() {

    cout << "\n---------------------------------\n";
    cout << "         BANK MANAGEMENT\n";
    cout << "---------------------------------\n";
    cout << "1. Create Account\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "---------------------------------\n";
}

void BankSystem::createAccount() {
    Account newAccount;
    newAccount.createAccount();
    accounts.push_back(newAccount);
}

void BankSystem::login() {

    system("cls");
    cout << "---------------------------------\n";
    cout << "              LOGIN\n";
    cout << "---------------------------------\n";

    long long accountNo;
    string pin;

    cout << "Enter Account Number: ";
    cin >> accountNo;
    cout << "Enter PIN: ";
    cin >> pin;

    for (int i = 0; i < accounts.size(); i++) {
        if (accountNo == accounts[i].getAccountNumber() && pin == accounts[i].getpin()) {
            userIndex = i;
            system("cls");
            cout << "\nLogin Successful\n";
            Sleep(800);
            return;
        }
    }

    cout << "Login Failed. Incorrect Details.\n";
    userIndex = -1;
}

void BankSystem::showAccountMenu() {

    int userChoice;
    do {
        cout << "\n---------------------------------\n";
        cout << "            ACCOUNT MENU\n";
        cout << "---------------------------------\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Show Account Details\n";
        cout << "5. Logout\n";
        cout << "---------------------------------\n";
        cout << "Enter Choice: ";
        cin >> userChoice;

        double amount;

        switch (userChoice) {
            case 1:
                cout << "Enter Amount: ";
                cin >> amount;
                accounts[userIndex].deposit(amount);
                break;
            case 2:
                cout << "Enter Amount: ";
                cin >> amount;
                accounts[userIndex].withdraw(amount);
                break;
            case 3:
                accounts[userIndex].checkBalance();
                break;
            case 4:
                accounts[userIndex].showDetails();
                break;
            case 5:
                cout << "Logging Out...\n";
                Sleep(700);
                break;
            default:
                cout << "Invalid Choice. Try Again.\n";
        }

    } while (userChoice != 5);
}

int main() {
    BankSystem bank;
    bank.run();
    return 0;
}