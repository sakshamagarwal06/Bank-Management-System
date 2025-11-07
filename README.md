# Bank Management System

## What is this?
A simple bank system made in C++ where you can create accounts, deposit/withdraw money, and save everything to a file. Built for learning OOP concepts.

## How to Run

### Windows (Command Line):
g++ main.cpp -o main
main.exe



### Linux/Mac:
g++ main.cpp -o main
./main



### Code::Blocks:
Just open `main.cpp` and press **F9**

## What does it do?

1. You enter how many accounts you want (max 10)
2. For each account, add: account number, name, type, starting balance
3. Choose to deposit, withdraw, or skip for each account
4. See all account details at the end
5. All data is saved in `accountdata.txt`

## Features

- Create new accounts
- Deposit and withdraw money
- Show all accounts
- Check for duplicate account numbers
- Save data to file automatically

## OOP Concepts I Used

| Concept | What I Did |
|---------|-----------|
| Class | Created `Account` class |
| Private Data | Hidden account number, name, balance |
| Constructor | Initialize new accounts with empty data |
| Static | `totalAcc` counts all accounts |
| Array of Objects | `acc[10]` stores up to 10 accounts |
| Functions | `addAcc()`, `putMoney()`, `getMoney()` |
| Friend Function | `printNo()` accesses private data |
| Operator Overload | `==` to check duplicate account numbers |
| Inheritance | `VIPAcc` inherits from `Person` and `Account` |
| Virtual Function | `msg()` works differently in both classes |
| File Handling | Save accounts to `accountdata.txt` |

## File Format

Each account is saved like this:
==========================================
-Account Details

-Acc No: 312313

-Name: saksham

-Type: savings

-Balance: 16006


## Limits

- Can only add, deposit, withdraw (no edit/delete)
- Numbers only for account number and amount

## How to Test

1. Open 2-3 accounts with different numbers
2. Try deposit and withdraw on each
3. Open `accountdata.txt` to see saved data
4. Try using same account number twice to see warning



## Note

This is a college project for learning OOP. The code focuses on understanding concepts rather than being a real banking app.

---

**Date:** November 2025  
**For:** College OOP Project



