#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Account {
private:
    int accNo;
    char name[50];
    char accType[20];
    double bal;
public:
    static int totalAcc;
    
    Account() {
        accNo = 0;
        strcpy(name, "");
        strcpy(accType, "");
        bal = 0;
    }
    
    void addAcc() {
        char temp[100];
        cout << "\nEnter Account Number: ";
        cin.getline(temp, 100);
        accNo = atoi(temp);
        
        cout << "Enter Name: ";
        cin.getline(name, 50);
        
        cout << "Account Type (Savings/Current): ";
        cin.getline(accType, 20);
        
        cout << "Initial Balance: ";
        cin.getline(temp, 100);
        bal = atof(temp);
        
        totalAcc++;
    }
    
    void display() {
        cout << "\nAccount Number: " << accNo << endl;
        cout << "Name: " << name << endl;
        cout << "Type: " << accType << endl;
        cout << "Balance: " << bal << endl;
    }
    
    void putMoney() {
        char temp[100];
        double money;
        
        cout << "How much to deposit? ";
        cin.getline(temp, 100);
        money = atof(temp);
        
        if (money > 0) {
            bal = bal + money;
            cout << "Success! New balance: " << bal << endl;
        }
        else {
            cout << "Invalid amount" << endl;
        }
    }
    
    void getMoney() {
        char temp[100];
        double money;
        
        cout << "How much to withdraw? ";
        cin.getline(temp, 100);
        money = atof(temp);
        
        if (money > 0 && bal >= money) {
            bal = bal - money;
            cout << "Success! New balance: " << bal << endl;
        }
        else {
            cout << "Not enough balance or invalid" << endl;
        }
    }
    
    void saveData() {
        ofstream file;
        file.open("accountdata.txt", ios::app);
        file << "==========================================\n";
        file << "Account Details\n";
        file << "==========================================\n";
        file << "Acc No: " << accNo << "\n";
        file << "Name: " << name << "\n";
        file << "Type: " << accType << "\n";
        file << "Balance: " << bal << "\n";
        file << "==========================================\n\n";
        file.close();
    }
    
    int getNo() {
        return accNo;
    }
    
    friend void printNo(Account &);
    
    bool operator==(Account &other) {
        return accNo == other.accNo;
    }
};

int Account::totalAcc = 0;

void printNo(Account &a) {
    cout << "[Info] Account No: " << a.accNo << endl;
}

class Person {
public:
    virtual void msg() {
        cout << "Account created!\n";
    }
};

class VIPAcc : public Person, public Account {
public:
    void msg() {
        cout << "Welcome VIP Customer!\n";
    }
};

int main() {
    char temp[100];
    int n;
    
    cout << "How many accounts? ";
    cin.getline(temp, 100);
    n = atoi(temp);
    
    Account acc[10];
    
    for (int i = 0; i < n; i++) {
        cout << "\n--- Account " << (i+1) << " ---\n";
        acc[i].addAcc();
        acc[i].saveData();
        printNo(acc[i]);
        
        // CHECK FOR DUPLICATE - NOW FIXED!
        bool isDuplicate = false;
        for (int j = 0; j < i; j++) {
            if (acc[i] == acc[j]) {
                isDuplicate = true;
                cout << "WARNING: Account number already exists!\n";
                break;
            }
        }
        
        cout << "Deposit/Withdraw? (d/w/skip): ";
        cin.getline(temp, 100);
        
        if (temp[0] == 'd') {
            acc[i].putMoney();
        }
        else if (temp[0] == 'w') {
            acc[i].getMoney();
        }
    }
    
    cout << "\n=== All Accounts ===\n";
    for (int i = 0; i < n; i++) {
        acc[i].display();
    }
    
    cout << "\nTotal Accounts: " << Account::totalAcc << endl;
    
    VIPAcc vip;
    Person *ptr = &vip;
    ptr->msg();
    
    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}
