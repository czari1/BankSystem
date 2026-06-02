#include "Account.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <iomanip>

Account::Account(std::string number, std::string name, 
                std::string surname, double startingBalance)
            : m_number(std::move(number))
            , m_name(std::move(name))
            , m_surname(std::move(surname))
            , m_balance(startingBalance) {}
            
void Account::deposit(double amount) {

    if (amount <= 0.0) {
        throw Exception::InvalidAmountException();
    }

    m_balance += amount;
}

void Account::withdraw(double amount) {

    if (amount <= 0.0) {
        throw Exception::InvalidAmountException();
    }

    if (amount > m_balance) {
        throw Exception::InsufficientFundsException(amount, m_balance);
    }

    m_balance -= amount;
}

void Account::printInfo() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Account number: " << m_number << "\n";
    std::cout << "Owners name: " << m_name << "\n";
    std::cout << "Owners surname: " << m_surname << "\n";
    std::cout << "Balance: " << m_balance << "\n";
}
