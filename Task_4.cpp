#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Transaction
{
private:
    string type;
    double amount;

public:
    Transaction(string t, double a)
    {
        type = t;
        amount = a;
    }

    void display()
    {
        cout << type << " : Rs. " << amount << endl;
    }
};

class Account
{
private:
    int accountNumber;
    double balance;
    vector<Transaction> history;

public:
    Account()
    {
        accountNumber = 0;
        balance = 0;
    }

    void setAccountNumber(int accNo)
    {
        accountNumber = accNo;
    }

    int getAccountNumber()
    {
        return accountNumber;
    }

    double getBalance()
    {
        return balance;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "INVALID AMOUNT!\n";
            return;
        }

        balance += amount;
        history.push_back(Transaction("Deposit", amount));

        cout << "DEPOSIT SUCCESSFUL!\n";
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "INVALID AMOUNT!\n";
            return;
        }

        if (amount > balance)
        {
            cout << "INSUFFICIENT BALANCE!\n";
            return;
        }

        balance -= amount;
        history.push_back(Transaction("Withdraw", amount));

        cout << "WITHDRAWL SUCCESSFUL!\n";
    }

    void transfer(double amount)
    {
        if (amount <= 0)
        {
            cout << "INVALID AMOUNT!\n";
            return;
        }

        if (amount > balance)
        {
            cout << "INSUFFICIENT BALANCE!\n";
            return;
        }

        balance -= amount;
        history.push_back(Transaction("Transfer", amount));

        cout << "TRANSFER SUCCESSFUL!\n";
    }

    void showBalance()
    {
        cout << "\nCURRESNT BALANCE : Rs. "  << balance << endl;
    }

    void showHistory()
    {
        if (history.empty())
        {
            cout << "\nNO TRANSACTION FOUND!\n";
            return;
        }

        cout << "\n===== TRANSACTION HISTORY =====\n";

        for (int i = 0; i < history.size(); i++)
        {
            cout << i + 1 << ". ";
            history[i].display();
        }
    }
};

class Customer
{
private:
    string name;
    Account account;

public:
    void createCustomer()
    {
        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        int accNo;

        cout << "Enter Account Number: ";
        cin >> accNo;

        account.setAccountNumber(accNo);

        cout << "\nACCOUNT CREATED SUCCCESSFULLY!\n";
    }

    void displayInfo()
    {
        cout << "\n===== CUSTOMER DETAILS =====\n";
        cout << "NAME : " << name << endl;
        cout << "ACCOUNT NUMBER : " << account.getAccountNumber() << endl;
        cout << "Balance : Rs. " << account.getBalance() << endl;
    }
    Account& getAccount()
    {
        return account;
    }
};

int main()
{
    Customer customer;
    int choice;
    bool accountCreated = false;
    do {
        cout << "====================================\n";
        cout << "     BANKING MANAGEMENT SYSTEM\n";
        cout << "====================================\n";
        cout << "1. ADD ACCOUNT\n";
        cout << "2. DEPOSIT\n";
        cout << "3. WITHDRAW\n";
        cout << "4. TRANSFER FUNDS\n";
        cout << "5. CHECK BALANCE\n";
        cout << "6. TRANSACTION HISTORY\n";
        cout << "7. CUSTOMER DETAILS\n";
        cout << "8. EXIT\n";
        cout << "====================================\n";

        cout << "ENTER CHOICE: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "INVALID INPUT!\n";
            continue;
        }
       
        switch (choice)
        {
        case 1:
        {
            customer.createCustomer();
            accountCreated = true;
            break;
        }
        case 2:
        {
            if (!accountCreated)
            {
                cout << "PLEASE CREATE AN ACCOUNT FIRST!\n";
                break;
            }
            double amount;

            cout << "ENTER AMOUNT TO DEPOSIT: ";
            cin >> amount;

            customer.getAccount().deposit(amount);
            break;
        }

        case 3:
        {
            if (!accountCreated)
            {
                cout << "PLEASE CREATE AN ACCOUNT FIRST!\n";
                break;
            }
            double amount;

            cout << "ENTER AMOUNT: ";
            cin >> amount;

            customer.getAccount().withdraw(amount);
            break;
        }

        case 4:
        {
            if (!accountCreated)
            {
                cout << "PLEASE CREATE AN ACCOUNT FIRST!\n";
                break;
            }
            double amount;

            cout << "ENTER AMOUNT: ";
            cin >> amount;

            customer.getAccount().transfer(amount);
            break;
        }
        case 5:
        {
            if (!accountCreated)
            {
                cout << "PLEASE CREATE AN ACCOUNT FIRST!\n";
                break;
            }
            customer.getAccount().showBalance();
            break;
        }
        case 6:
        {
            if (!accountCreated)
            {
                cout << "PLEASE CREATE AN ACCOUNT FIRST!\n";
                break;
            }
            customer.getAccount().showHistory();
            break;
        }
        case 7:
        {
            if (!accountCreated)
            {
                cout << "PLEASE CREATE AN ACCOUNT FIRST!\n";
                break;
            }
            customer.displayInfo();
            break;
        }
        case 8:
            cout << "\nTHANK YOU!\n";
            break;

        default:
            cout << "\nINVALID CHOICE!\n";
        }
        cout << endl;
        cout << endl;

    } while (choice != 8);
  
    return 0;
}