#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class BankAccount {
private:
    int accountNo;
    char holderName[50], type[20];
    double balance;
public:
    static int totalAccounts;

    BankAccount() {
        accountNo = 0;
        strcpy(holderName, "");
        strcpy(type, "");
        balance = 0;
    }

    void openAccount() {
        char temp[100];
        cout << "Enter Account No: ";
        cin.getline(temp, 100);
        accountNo = atoi(temp);

        cout << "Enter Holder Name: ";
        cin.getline(holderName, 50);

        cout << "Enter Account Type (Savings/Current): ";
        cin.getline(type, 20);

        cout << "Enter Initial Balance: ";
        cin.getline(temp, 100);
        balance = atof(temp);

        totalAccounts++;
    }

    void showAccount() {
        cout << "\n--- Account Details ---\n";
        cout << "Account No: " << accountNo << "\n";
        cout << "Name      : " << holderName << "\n";
        cout << "Type      : " << type << "\n";
        cout << "Balance   : " << balance << "\n";
        cout << "-----------------------\n";
    }

    void deposit() {
        char temp[100];
        double amt;
        cout << "Enter Amount to Deposit: ";
        cin.getline(temp, 100);
        amt = atof(temp);
        if (amt > 0) {
            balance += amt;
            cout << amt << " deposited. New balance: " << balance << endl;
        }
        else cout << "Invalid amount!\n";
    }

    void withdraw() {
        char temp[100];
        double amt;
        cout << "Enter Amount to Withdraw: ";
        cin.getline(temp, 100);
        amt = atof(temp);
        if (amt > 0 && balance - amt >= 0) {
            balance -= amt;
            cout << amt << " withdrawn. New balance: " << balance << endl;
        }
        else cout << "Insufficient balance or invalid amount!\n";
    }

    // >>>> FORMATTED FILE OUTPUT <<<<
    void saveToFile() {
        ofstream fout("accountdata.txt", ios::app);
        fout << "---------------------------\n";
        fout << "Account No : " << accountNo << "\n";
        fout << "Name       : " << holderName << "\n";
        fout << "Type       : " << type << "\n";
        fout << "Balance    : " << balance << "\n";
        fout << "---------------------------\n";
        fout.close();
    }

    int getAccountNo() { return accountNo; }

    friend void showFriend(BankAccount &);

    bool operator==(BankAccount &a2) { return accountNo == a2.accountNo; }
};

int BankAccount::totalAccounts = 0;

void showFriend(BankAccount &acc) {
    cout << "[Friend] Account No is: " << acc.accountNo << endl;
}

class Person {
public:
    virtual void welcome() { cout << "Bank account registration done!\n"; }
};

class VIPAccount : public Person, public BankAccount {
public:
    void welcome() { cout << "VIP Account: Special Welcome from Bank!\n"; }
};

int main() {
    BankAccount::totalAccounts = 0;
    char temp[100];
    int n;

    cout << "How many bank accounts to open? ";
    cin.getline(temp, 100);
    n = atoi(temp);

    BankAccount accounts[10];

    for (int i = 0; i < n; ++i) {
        cout << "\n--- Account #" << (i+1) << " ---\n";
        accounts[i].openAccount();
        accounts[i].saveToFile();
        showFriend(accounts[i]);

        if (i > 0 && accounts[i] == accounts[i-1])
            cout << "[Warning] Two accounts have same Account No!\n";

        cout << "Want to deposit or withdraw (d/w/skip)? ";
        cin.getline(temp, 100);
        if (strcmp(temp, "d") == 0) accounts[i].deposit();
        else if (strcmp(temp, "w") == 0) accounts[i].withdraw();
    }

    cout << "\n====== All Accounts Summary ======\n";
    for (int i = 0; i < n; ++i) {
        accounts[i].showAccount();
    }
    cout << "Total accounts opened: " << BankAccount::totalAccounts << endl;

    VIPAccount vip;
    Person *ptr = &vip;
    ptr->welcome();

    cout << "Press Enter to exit...";
    cin.get();
    return 0;
}
