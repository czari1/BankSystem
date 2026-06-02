#pragma once

#include "Account.hpp"
#include <vector>
#include <memory>

class Bank {
public:

    explicit Bank (std::string bankName);

    void createAccount(const std::string& number, const std::string& name, 
                       const std::string& surname, double startingBalance);
    
    Account& findAccount(const std::string& number);

    void listAllAccounts() const;

    const std::string& getBankName() const { return m_bankName; }

private:
    std::string m_bankName;
    std::vector<std::unique_ptr<Account>> m_accounts;
};