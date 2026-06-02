#include "Bank.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>

Bank::Bank(std::string name) 
    : m_bankName(std::move(name)) {}

void Bank::createAccount(const std::string& number, const std::string& name, 
                        const std::string& surname, double startingBalance) {
    
    auto it = std::find_if(m_accounts.begin(), m_accounts.end(), 
        [&number](const auto& acc) { return acc->getNumber() == number; });
    
    if (it != m_accounts.end()) {
        throw Exception::DuplicateAccountException(number);
    }

    m_accounts.push_back(std::make_unique<Account>(number, name, surname, startingBalance));
    std::cout << "Account number: " << number << " was created succesfully\n";
}

Account& Bank::findAccount(const std::string& number) {
    
    auto it = std::find_if(m_accounts.begin(), m_accounts.end(),
        [&number](const auto& acc) { return acc->getNumber() == number; });
    
    if (it == m_accounts.end()) {
        throw Exception::AccountNotFoundException(number);
    }

    return **it;
}

void Bank::listAllAccounts() const {

    if (m_accounts.empty()) {
        std::cout << "No registered accounts.\n";
        return;
    }

    std::cout << "\nAll accounts in " << m_bankName << ":\n";

    for (const auto& acc : m_accounts) {
        std::cout << "Account number: " << acc->getNumber() << "\n"
                  << "Owner's name: " << acc->getName() << "\n"
                  << "Owner's surname: "  << acc->getSurname() << "\n"
                  << "Balance: " << acc->getBalance() << " PLN\n\n"; 
    }

    std::cout << "\n";
}
