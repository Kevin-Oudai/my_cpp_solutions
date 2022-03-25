#include <iostream>
#include "Account.h"

void createAccounts(Account *accounts, int size)
{
    for (int i = 0; i < size; i++)
    {
        accounts[i].setId(i);
        accounts[i].setBalance(100);
    }
}

int displayMenu()
{
    std::cout << "Main Menu" << std::endl;
    std::cout << "1: Check Balance" << std::endl;
    std::cout << "2: Withdraw" << std::endl;
    std::cout << "3: Deposit" << std::endl;
    std::cout << "4: Exit" << std::endl;
    int choice;
    std::cout << "Enter a choice: ";
    std::cin >> choice;
    return choice;
}

void takeOut(Account *account)
{
    std::cout << "Enter an amount to withdraw: ";
    double amount;
    std::cin >> amount;
    account->withdraw(amount);
}

void putIn(Account *account)
{
    std::cout << "Enter an amount to deposit: ";
    double amount;
    std::cin >> amount;
    account->deposit(amount);
}

void startAtm(Account *accounts, int id)
{
    int choice = displayMenu();
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
            std::cout << "Balance: $" << accounts[id].getBalance() << std::endl;
            break;

        case 2:
            takeOut(&(accounts[id]));
            break;

        case 3:
            putIn(&(accounts[id]));
            break;

        case 4:
            break;

        default:
            startAtm(accounts, id);
            break;
        }
        choice = displayMenu();
    }
}

int main()
{
    const int size = 10;
    Account *accounts = new Account[size];
    createAccounts(accounts, size);
    int id;
    while (true)
    {
        std::cout << "Enter an id: ";
        std::cin >> id;
        startAtm(accounts, id);
    }

    return 0;
}