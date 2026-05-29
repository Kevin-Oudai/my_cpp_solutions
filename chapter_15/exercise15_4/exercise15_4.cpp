#include <iostream>
#include "CheckingAccount.h"
#include "SavingsAccount.h"

void printAccount(const Account &account)
{
    std::cout << account.toString() << std::endl;
}

int main()
{
    Account account(1001, 1000, 4.5);
    SavingsAccount savings(1002, 1000, 4.5);
    CheckingAccount checking(1003, 1000, 4.5, 500);

    account.withdraw(200);
    savings.withdraw(1200);
    checking.withdraw(1200);

    printAccount(account);
    printAccount(savings);
    printAccount(checking);

    return 0;
}
