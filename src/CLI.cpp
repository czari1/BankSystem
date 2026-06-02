#include "CLI.hpp"
#include <iostream>
#include <limits>
#include <string>

namespace HelperFunctions {
    double readDouble(const std::string& prompt) {
        double value = 0.0;
        
        while (true) {
            std::cout << prompt;
        
            if (std::cin >> value) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                return value;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Incorrect value.PLease try again.\n";
        }    
    }

    std::string readLine(const std::string& prompt) {
        std::string line;
        std::cout << prompt;
        std::getline(std::cin, line);
        return line;
    }
}

namespace CLI {
    int showMainMenu() {
        std::cout << "Bank System\n";
        std::cout << "1. Create new account. \n";
        std::cout << "2. Deposit funds. \n";
        std::cout << "3. Withdraw funds. \n";
        std::cout << "4. Account information. \n";
        std::cout << "5. List all accounts. \n";
        std::cout << "0. Exit";

        int choice = 0;
        
        while (true) {
            std::cout << "Choose option: ";
        
            if (std::cin >> choice) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                return choice;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please choose an integer.\n";
    }
    }

    void handleCreateAccount(Bank& bank) {
        std::cout << "\nCreating new account\n";
        std::string number = HelperFunctions::readLine("Account number: ");
        std::string name  =  HelperFunctions::readLine("Owners name: ");
        std::string surname =  HelperFunctions::readLine("Owners surname: ");
        double balance = HelperFunctions::readDouble("Starting balance (PLN): ");

        try {
            bank.createAccount(number, name, surname, balance);
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    void handleDeposit(Bank& bank) {
        std::cout << "\nDeposit\n";
        std::string number = HelperFunctions::readLine("Account number: ");
        double amount = HelperFunctions::readDouble("Amount (PLN) : ");

        try {
            Account& acc = bank.findAccount(number);
            acc.deposit(amount);
            std::cout << "Deposit completed sucsessfully. New balance: "
                    << acc.getBalance() << " PLN\n";
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    void handleWithdraw(Bank& bank) {
        std::cout << "\nBalance withdrawal\n";
        std::string number = HelperFunctions::readLine("Account number: ");
        double amount = HelperFunctions::readDouble("Amount (PLN) : ");

        try {
            Account& acc = bank.findAccount(number);
            acc.withdraw(amount);
            std::cout << "Withdrwawal completed successfully. New balance: "
                    << acc.getBalance() << " PLN\n";
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    void handleShowAccount(Bank& bank) {
        std::cout << "\nAccount information\n";
        std::string number = HelperFunctions::readLine("Account number: ");

        try {
            bank.findAccount(number).printInfo();
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    void handleListAccounts(const Bank& bank) {
        bank.listAllAccounts();
    }

    void run(Bank& bank) {
        bool running = true;

        while (running) {
            int choice = showMainMenu();

            switch (choice) {
                case 1: handleCreateAccount(bank); break;
                case 2: handleDeposit(bank);       break;
                case 3: handleWithdraw(bank);      break;
                case 4: handleShowAccount(bank);   break;
                case 5: handleListAccounts(bank);  break;
                case 0:
                    std::cout << "\nGoodbye!\n";
                    running = false;
                    break;
                default:
                    std::cout << "Unknown number. Please choose between 0 and 5.\n";
            }
        }
    }

}

