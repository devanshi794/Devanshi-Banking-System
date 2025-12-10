#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    double balance;

public:
    double accountNumber;
    string accountHolderName;

    BankAccount()
    {
        accountNumber = 0;
        accountHolderName = "";
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient Balance!" << endl;
    }

    double getBalance()
    {
        return balance;
    }

    void addInterest(double interest)
    {
        balance += interest;
    }

    void displayAccountInfo()
    {
        cout << endl
             << "==========================" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount
{
private:
    int interestRate;

public:
    double interest;

    SavingsAccount()
    {
        interestRate = 10;
        interest = 0;
    }

    void calculateInterest()
    {
        interest = getBalance() * interestRate / 100;
        addInterest(interest);
    }
};

class CheckingAccount : public BankAccount
{
};

class FixedDepositAccount : public BankAccount
{
};

int main()
{
    SavingsAccount bankAcc;
    double balance = 0;
    int choice, ch;

    do
    {
        cout << endl
             << "Select Your Account Type." << endl;
        cout << "1. Saving Account" << endl;
        cout << "2. Checking Account" << endl;
        cout << "3. Fixed Deposit Account" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            do
            {
                cout << endl
                     << "===== Saving Account Menu =====" << endl;
                cout << "1. Enter Account Details" << endl;
                cout << "2. Display Account Details" << endl;
                cout << "3. Deposit Amount" << endl;
                cout << "4. Go to Main Menu" << endl;
                cout << "Enter Your Choice: ";
                cin >> ch;

                switch (ch)
                {
                case 1:
                    cout << endl
                         << "Enter Bank Account Details" << endl;
                    cout << "Account Number: ";
                    cin >> bankAcc.accountNumber;

                    cin.ignore();
                    cout << "Account Holder Name: ";
                    getline(cin, bankAcc.accountHolderName);

                    cout << "Initial Balance: ";
                    cin >> balance;

                    bankAcc.deposit(balance);
                    bankAcc.calculateInterest();
                    break;

                case 2:
                    bankAcc.displayAccountInfo();
                    break;

                case 3:
                    cout << "Enter Deposit Amount: ";
                    cin >> balance;

                    bankAcc.deposit(balance);
                    bankAcc.calculateInterest();
                    cout << "Amount Deposited with Interest!" << endl;
                    break;

                case 4:
                    break;

                default:
                    cout << "Invalid Choice!" << endl;
                }
            } while (ch != 4);
            break;

        case 2:
            cout << "Checking Account feature not implemented yet." << endl;
            break;

        case 3:
            cout << "Fixed Deposit Account feature not implemented yet." << endl;
            break;

        case 0:
            cout << "Exiting Program..." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
