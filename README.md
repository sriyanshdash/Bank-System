# Bank-System
A CLI-based C++ application simulating secure bank operations with PIN access and file-based account storage.

# 🏦 Bank Account Management System (C++)

## 🔍 Overview
This is a simple **Bank Account Management System** built using **C++**. It is a command-line application that simulates basic banking operations, including account creation, PIN-protected login, deposits, withdrawals, and data persistence using file handling. This project is designed as a beginner-level introduction to C++ and object-oriented programming.

---

## 🌐 Features
- Create a new bank account with a 4-digit PIN
- Secure login with PIN verification
- Deposit and withdraw money
- View account balance and holder information
- Save and load account data to/from a file (`accounts.txt`)
- Menu-driven CLI interface

---

## 💪 Technologies Used
- **Language:** C++
- **Concepts Covered:**
  - Object-Oriented Programming (Classes, Objects)
  - File Handling (Reading/Writing files)
  - Input/Output streams
  - Vectors and Data Structures
  - CLI-based interface

---

## 📂 Project Structure
```
BankSystem/
├── main.cpp          // Main logic and user interface
├── account.h         // Account class declaration
├── account.cpp       // Account class implementation
├── accounts.txt      // Auto-generated file storing user data
└── README.md         // Project description (optional for GitHub)
```

---

## 🔄 Program Flow
1. Load existing accounts from `accounts.txt` at startup
2. Display a menu:
   - Create Account
   - View Account
   - Deposit Money
   - Withdraw Money
   - Exit
3. User inputs choice and follows prompts
4. Changes are saved back to `accounts.txt` after any transaction

---

## 📅 Example File Format (`accounts.txt`)
```
1001,John Doe,5000.00,1234
1002,Alice Kumar,2500.00,5678
```
Each line stores: `accountNumber,name,balance,PIN`

---

## 💡 How to Compile and Run

### ✅ Using G++:
```bash
g++ main.cpp account.cpp -o bank
./bank
```

### ✅ Using VS Code:
1. Install the C++ Extension (by Microsoft)
2. Open the project folder in VS Code
3. Open terminal and run the above commands

---

## 🎓 Learning Objectives
- Understand class structures in C++
- Learn how to serialize/deserialize objects
- Work with vectors and object collections
- Handle persistent data using files
- Implement simple security using PIN verification

---

## 👨‍💻 Author
Developed by *[Your Name]* while preparing for roles in software development and financial technology (e.g., UBS Graduate Talent Program).

---

## 🌍 License
This project is open-source under the MIT License.

---

## 📢 Notes for Extension
- Add interest calculation on deposits  
- Add transaction logs  
- Mask PIN input for added security  
- Build a GUI version with Qt or SFML in future  
