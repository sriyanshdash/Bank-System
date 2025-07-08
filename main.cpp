#include <iostream>
#include <vector>
#include <fstream>
#include "account.h"

std::vector<Account> accounts;

void loadAccounts() {
    std::ifstream inFile("accounts.txt");
    if (!inFile) return;
    std::string line;
    while (getline(inFile, line)) {
        Account acc;
        acc.deserialize(line);
        accounts.push_back(acc);
    }
    inFile.close();
}

void saveAccounts() {
    std::ofstream outFile("accounts.txt");
    for (auto& acc : accounts) {
        outFile << acc.serialize() << "\n";
    }
    outFile.close();
}

Account* findAccount(int accNo) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accNo)
            return &acc;
    }
    return nullptr;
}

bool verifyPIN(Account* acc) {
    int pinInput;
    std::cout << "Enter PIN: ";
    std::cin >> pinInput;
    return acc->getPIN() == pinInput;
}

int main() {
    loadAccounts();
    int choice;

    while (true) {
        std::cout << "\n===== 🏦 Bank Management System =====\n";
        std::cout << "1. Create New Account\n";
        std::cout << "2. View Account Details\n";
        std::cout << "3. Deposit Money\n";
        std::cout << "4. Withdraw Money\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int accNo, pin;
            std::string name;
            std::cout << "Enter account number: ";
            std::cin >> accNo;
            std::cin.ignore();
            std::cout << "Enter account holder name: ";
            std::getline(std::cin, name);
            std::cout << "Set a 4-digit PIN: ";
            std::cin >> pin;

            Account acc;
            acc.createAccount(accNo, name, pin);
            accounts.push_back(acc);
            saveAccounts();

        } else if (choice == 2) {
            int accNo;
            std::cout << "Enter account number: ";
            std::cin >> accNo;
            Account* acc = findAccount(accNo);
            if (acc && verifyPIN(acc)) {
                acc->displayAccount();
            } else {
                std::cout << "❌ Invalid account or wrong PIN.\n";
            }

        } else if (choice == 3) {
            int accNo;
            double amt;
            std::cout << "Enter account number: ";
            std::cin >> accNo;
            Account* acc = findAccount(accNo);
            if (acc && verifyPIN(acc)) {
                std::cout << "Enter amount to deposit: ";
                std::cin >> amt;
                acc->deposit(amt);
                saveAccounts();
            } else {
                std::cout << "❌ Invalid account or wrong PIN.\n";
            }

        } else if (choice == 4) {
            int accNo;
            double amt;
            std::cout << "Enter account number: ";
            std::cin >> accNo;
            Account* acc = findAccount(accNo);
            if (acc && verifyPIN(acc)) {
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amt;
                acc->withdraw(amt);
                saveAccounts();
            } else {
                std::cout << "❌ Invalid account or wrong PIN.\n";
            }

        } else if (choice == 5) {
            std::cout << "👋 Thank you for using the Bank System!\n";
            break;
        } else {
            std::cout << "❌ Invalid choice. Try again.\n";
        }
    }

    return 0;
}
