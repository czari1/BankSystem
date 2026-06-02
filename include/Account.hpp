#pragma once

#include <string>

class Account {
public:
    Account(std::string number, std::string name, std::string surname,
            double startingBalance = 0.0);

    void deposit(double amount);
    void withdraw(double amount);

    const std::string& getNumber() const { return m_number; }
    const std::string& getName() const { return m_name; }
    const std::string& getSurname() const { return m_surname; }
    double getBalance() const { return m_balance; }

    void printInfo() const;

private:
    std::string m_number;
    std::string m_name;
    std::string m_surname;
    double m_balance;
};