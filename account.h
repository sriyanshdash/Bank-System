#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    int accountNumber;
    std::string name;
    double balance;
    int pin;

public:
    Account();
    void createAccount(int accNo, std::string accName, int accPin);
    void displayAccount() const;
    void deposit(double amount);
    bool withdraw(double amount);
    int getAccountNumber() const;
    int getPIN() const;

    std::string serialize() const;
    void deserialize(const std::string& line);
};

#endif
