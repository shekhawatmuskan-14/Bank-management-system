#include <iostream>
#include <string>
using namespace std;

class Account {
public:
    int accNo;
    string name;
    double balance;
};

class Bank {
    Account a[100];
    int n = 0;

    int tAcc[500];
    string tType[500];
    double tAmount[500];
    int total = 0;

public:
    void createAccount() {
        if (n == 100) {
            cout << "Bank account limit reached!\n";
            return;
        }

        cout << "Enter account number: ";
        cin >> a[n].accNo;

        for (int i = 0; i < n; i++) {
            if (a[i].accNo == a[n].accNo) {
                cout << "Account number already exists!\n";
                return;
            }
        }

        cout << "Enter account holder name: ";
        cin >> ws;
        getline(cin, a[n].name);

        cout << "Enter opening balance: ";
        cin >> a[n].balance;

        if (a[n].accNo <= 0 || a[n].balance < 0) {
            cout << "Invalid account number or balance!\n";
            return;
        }

        cout << "Account created successfully!\n";

        if (a[n].balance > 0) {
            tAcc[total] = a[n].accNo;
            tType[total] = "Opening Balance";
            tAmount[total] = a[n].balance;
            total++;
        }

        n++;
    }

    int findAccount(int id) {
        for (int i = 0; i < n; i++) {
            if (a[i].accNo == id) {
                return i;
            }
        }
        return -1;
    }

    void showAccounts() {
        if (n == 0) {
            cout << "No accounts found!\n";
            return;
        }

        cout << "\nAccount Details\n";
        cout << "-----------------------------\n";

        for (int i = 0; i < n; i++) {
            cout << "Account Number: " << a[i].accNo << endl;
            cout << "Name: " << a[i].name << endl;
            cout << "Balance: Rs. " << a[i].balance << endl;
            cout << "-----------------------------\n";
        }
    }

    void deposit() {
        int id;
        double amount;

        cout << "Enter account number: ";
        cin >> id;

        int pos = findAccount(id);

        if (pos == -1) {
            cout << "Account not found!\n";
            return;
        }

        cout << "Enter deposit amount: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Enter a valid amount!\n";
            return;
        }

        a[pos].balance += amount;

        tAcc[total] = id;
        tType[total] = "Deposit";
        tAmount[total] = amount;
        total++;

        cout << "Money deposited successfully!\n";
        cout << "Current balance: Rs. " << a[pos].balance << endl;
    }

    void withdraw() {
        int id;
        double amount;

        cout << "Enter account number: ";
        cin >> id;

        int pos = findAccount(id);

        if (pos == -1) {
            cout << "Account not found!\n";
            return;
        }

        cout << "Enter withdrawal amount: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Enter a valid amount!\n";
            return;
        }

        if (amount > a[pos].balance) {
            cout << "Insufficient balance!\n";
            return;
        }

        a[pos].balance -= amount;

        tAcc[total] = id;
        tType[total] = "Withdrawal";
        tAmount[total] = amount;
        total++;

        cout << "Money withdrawn successfully!\n";
        cout << "Remaining balance: Rs. " << a[pos].balance << endl;
    }

    void checkBalance() {
        int id;

        cout << "Enter account number: ";
        cin >> id;

        int pos = findAccount(id);

        if (pos == -1) {
            cout << "Account not found!\n";
        } else {
            cout << "Account Holder: " << a[pos].name << endl;
            cout << "Current Balance: Rs. " << a[pos].balance << endl;
        }
    }

    void history() {
        int id;
        bool found = false;

        cout << "Enter account number: ";
        cin >> id;

        if (findAccount(id) == -1) {
            cout << "Account not found!\n";
            return;
        }

        cout << "\nTransaction History\n";
        cout << "-----------------------------\n";

        for (int i = 0; i < total; i++) {
            if (tAcc[i] == id) {
                cout << "Type: " << tType[i] << endl;
                cout << "Amount: Rs. " << tAmount[i] << endl;
                cout << "-----------------------------\n";
                found = true;
            }
        }

        if (!found) {
            cout << "No transactions found!\n";
        }
    }
};

int main() {
    Bank b;
    int ch;

    do {
        cout << "\n===== BANKING MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Check Balance\n";
        cout << "6. Transaction History\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                b.createAccount();
                break;

            case 2:
                b.showAccounts();
                break;

            case 3:
                b.deposit();
                break;

            case 4:
                b.withdraw();
                break;

            case 5:
                b.checkBalance();
                break;

            case 6:
                b.history();
                break;

            case 0:
                cout << "Thank you for using our bank system!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (ch != 0);

    return 0;
}