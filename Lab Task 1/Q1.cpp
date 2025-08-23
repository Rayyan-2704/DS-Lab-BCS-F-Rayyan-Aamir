/* Q1. Suppose you are developing a bank account management system, and you have defined the BankAccount class with the required constructors.
You need to demonstrate the use of these constructors in various scenarios.
1. Default Constructor Usage: Create a default-initialized BankAccount object named account1.
   Print out the balance of account1.
2. Parameterized Constructor Usage: Create a BankAccount object named account2 with an initial balance of $1000.
   Print out the balance of account2.
3. Copy Constructor Usage: Using the account2 you created earlier, create a new BankAccount object named account3 using the copy constructor.
   Deduct $200 from account3 and print out its balance. Also, print out the balance of account2 to ensure it hasn't been affected by the
   transaction involving account3. */

#include <iostream>
using namespace std;

class BankAccount
{
    double balance;

public:
    // Default Constructor
    BankAccount() : balance(0.0) {}

    // Parameterized Constructor
    BankAccount(double bal) : balance(bal) {}

    // Copy Constructor
    BankAccount(const BankAccount &other)
    {
        balance = other.balance;
    }

    void deductAmount(double amount)
    {
        if (amount > balance)
        {
            cout << "Cannot deduct as amount exceeds current balance." << endl;
            return;
        }
        balance -= amount;
    }

    double getBalance() const { return balance; }
};

int main()
{
    BankAccount account1, account2(1000);
    cout << "Current balance of account 1: $" << account1.getBalance() << endl;
    cout << "Current balance of account 2: $" << account2.getBalance() << endl;

    BankAccount account3 = account2;
    cout << "Current balance of account 3: $" << account3.getBalance() << endl;
    account3.deductAmount(200);

    cout << "Current balance of account 3 (after deduction of account 3): $" << account3.getBalance() << endl;
    cout << "Current balance of account 2 (after deduction of account 3): $" << account2.getBalance() << endl;

    return 0;
}