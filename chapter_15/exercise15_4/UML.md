# Exercise 15.4 UML

```text
Account
-------------------------------
- id: int
- balance: double
- annualInterestRate: double
- dateCreated: string
-------------------------------
+ withdraw(amount): void
+ deposit(amount): void
+ toString() const: string

SavingsAccount extends Account
-------------------------------
+ withdraw(amount): void
+ toString() const: string

CheckingAccount extends Account
-------------------------------
- overdraftLimit: double
-------------------------------
+ withdraw(amount): void
+ toString() const: string
```
