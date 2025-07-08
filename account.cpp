#include "account.h"
#include <iostream>
#include <sstream>

Account::Account() {
    accountNumber = 0;
    name = "";
    balance = 0.0;
    pin = 0;
}

void Account::createAccount(int accNo, std::string accName, int accPin) {
    accountNumber = accNo;
    name = accName;
    balance = 0.0;
    pin = accPin;
    std::cout << "✅ Account created successfully!\n";
}

void Account::displayAccount() const {
    std::cout << "\n👤 Account Holder: " << name << "\n";
    std::cout << "🏦 Account Number: " << accountNumber << "\n";
    std::cout << "💰 Balance: ₹" << balance << "\n\n";
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "💸 ₹" << amount << " deposited. New balance: ₹" << balance << "\n";
    }
}

bool Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        std::cout << "💵 ₹" << amount << " withdrawn. Remaining balance: ₹" << balance << "\n";
        return true;
    } else {
        std::cout << "❌ Insufficient balance!\n";
        return false;
    }
}

int Account::getAccountNumber() const {
    return accountNumber;
}

int Account::getPIN() const {
    return pin;
}

std::string Account::serialize() const {
    std::ostringstream oss;
    oss << accountNumber << "," << name << "," << balance << "," << pin;
    return oss.str();
}

void Account::deserialize(const std::string& line) {
    std::istringstream iss(line);
    std::string token;
    getline(iss, token, ',');
    accountNumber = std::stoi(token);
    getline(iss, name, ',');
    getline(iss, token, ',');
    balance = std::stod(token);
    getline(iss, token, ',');
    pin = std::stoi(token);
}
