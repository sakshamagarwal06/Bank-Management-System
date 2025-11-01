# Bank Management System

## Project Description

A comprehensive **C++ Object-Oriented Bank Management System** built for practicals, viva, and project submission. This system allows users to open bank accounts, deposit or withdraw money, and print all account details. Every OOP concept required by the syllabus is clearly demonstrated and mapped for easy explanation.

---

## Features

- **Multi-Account Management:** Register up to 10 bank accounts per session
- **Account Data Management:** Capture Account No, Holder Name, Type, and Balance
- **Deposit/Withdraw Operations:** Update balances for each account
- **Formatted Data Output:** Save all account records in a readable, card-style format to `accountdata.txt`
- **Duplicate Account Detection:** Warns if two accounts have the same Account No (operator overloading)
- **OOP-centric Design:** Demonstrates classes/objects, encapsulation, inheritance, polymorphism, static, friend function, operator overloading, arrays, and file handling

---

## Technical Stack

- **Language:** C++ (Standard C++11)
- **Compiler:** MinGW (GCC) or equivalent C++ compiler
- **IDE:** Code::Blocks, Dev C++, or any C++ IDE
- **Dependencies:** Standard C++ libraries (`iostream`, `fstream`, `cstring`)

---

## Installation & Setup

### Compile with Code::Blocks:
1. Open `main.cpp` in Code::Blocks
2. Press **F9** to compile and execute
3. Program runs immediately with interactive prompts

### Compile from Command Line (Windows):
g++ main.cpp -o main
main.exe



### Compile from Command Line (Linux/macOS):
g++ main.cpp -o main
./main



---

## OOP Concepts Implemented

### 1. Classes and Objects
- `BankAccount` class encapsulates bank account data and operations
- Multiple account objects created and managed within an array

### 2. Encapsulation
- Private data members (accountNo, holderName, type, balance)
- Public interface (openAccount, deposit, withdraw, showAccount, etc.)
- Encapsulated data for security and integrity

### 3. Constructor
- Default constructor initializes every BankAccount object with default values

### 4. Static Members
- `static int totalAccounts` — class-level counter for all accounts
- Demonstrates static variable, persists across all objects

### 5. Arrays of Objects
- `BankAccount accounts[10]` — process up to 10 accounts in a single session

### 6. Member Functions
- `openAccount()` — Get input for all private data via prompts
- `deposit()`, `withdraw()` — Modify balances per account
- `showAccount()` — Print data in a tidy format
- `saveToFile()` — Persist data in human-readable, card-style file

### 7. Friend Function
- `friend void showFriend(BankAccount&)` — Can access and print Account No (private) from outside

### 8. Operator Overloading
- `bool operator==(BankAccount &)` — Compares two accounts by Account No for duplicate detection

### 9. Inheritance and Polymorphism
- `Person` is an abstract base class with virtual `welcome()`
- `VIPAccount : public Person, public BankAccount`
- Demonstrates multiple inheritance and polymorphic function override

### 10. File Handling (I/O)
- `ofstream` object used in `saveToFile()` to output data card for every registered account
- Append mode (`ios::app`) ensures no data loss

---

## Project File Structure

Bank-Management-System/

├── main.cpp # - Full C++ source code

├── README.md # -  Project documentation (this file)

├── accountdata.txt # -  Output: Formatted, human-readable data cards

└── .gitignore # -  (optional) Ignore binaries/output files



---

## Data Storage Format

Every registered account is stored *as a neat info card* in `accountdata.txt`:

Account No : 213
Name : saksham
Type : savings
Balance : 1500


---

## System Specifications

- **Account No format:** Positive integer (example: 213134)
- **Maximum Accounts:** 10 per session (for easy batch and viva)
- **Storage:** Plain text file, append mode
- **Supported Operations:** Register, deposit, withdraw, show all
- **No edit or delete (see enhancements)**

---

## Implementation Highlights

- **Robust Input:** Uses `cin.getline()` for strings, validated parsing (atoi, atof) for numbers
- **Fully Encapsulated:** All account variables private; only accessible via public functions
- **Operator Overload in Use:** Safe duplicate detection
- **Professional Output:** Account info displayed as formatted card in terminal and text file

---

## Code Quality Features

- Clear, structured, and commented code
- No STL (arrays only) so beginner-friendly and practical-exam safe
- Each OOP concept implemented with a specific, named function or section
- Private data, public interface, and friend function boundaries are clear
- Static total, arrays, and virtual functions all demonstrated

---

## Future Enhancement Opportunities

- Add account search by Account No (to demonstrate traversal/mutators)
- Implement edit/update or delete account (logical deletion with active flag)
- Add transaction summary/history for each account
- Allow user authentication (add PIN field)
- Integrate SQLite/MySQL or web interface

---

## Academic Value

**This project is built to fully satisfy undergraduate C++ OOP syllabi, especially for Indian universities** (like PIET). It covers:
- Class/object, encapsulation, constructor, static, array of objects
- member/friend functions, operator overloading, inheritance, polymorphism
- file handling and formatted output

Every answer you need in viva can be pointed to an exact code section from this README.

---

## Testing Recommendations

1. Register 1, then multiple accounts (check all data fields)
2. After every account, try deposit, withdraw, skip; confirm balance updates
3. Open two accounts with same Account No to test duplicate detection (== overload)
4. Open `accountdata.txt` for formatted output (cards should be clear and readable)
5. Show summary in terminal matches file for each session

---

## Status

**Ready for Academic Submission**  
**Last Updated:** November 2, 2025  
**Version:** 1.0  
**Project Type:** C++ OOP Mini Project  
**Institution:** Poornima Institute of Engineering and Technology (PIET)

---



