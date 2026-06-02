#pragma once

#include <stdexcept>
#include <string>

namespace Exception {

class InvalidAmountException : public std::runtime_error {
public:
    explicit InvalidAmountException() 
    : std::runtime_error("Amount have to be greater than 0.") {}
};

class InsufficientFundsException : public std::runtime_error {
public:
    InsufficientFundsException(double requested, double available)
    : std::runtime_error("Not enough balance: requested " 
                        + std::to_string(requested) 
                        + " PLN, available: "
                        + std::to_string(available)
                        + " PLN") 
                        {}
};

class AccountNotFoundException : public std::runtime_error {
public:
    explicit AccountNotFoundException(const std::string& number)
    : std::runtime_error("No account with this number:  " + number) {}
};

class DuplicateAccountException : public std::runtime_error {
public:
    explicit DuplicateAccountException(const std::string& number)
    : std::runtime_error("Account with this " + number + " already exists.") {}
};

}