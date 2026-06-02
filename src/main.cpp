#include "Bank.hpp"
#include "CLI.hpp"

int main() {
    Bank bank("Bank AGH");

    // Kilka przykładowych kont ułatwia testowanie bez wpisywania danych
    bank.createAccount("PL10 1020 0001", "Jan", "Kowalski",   1000.00);
    bank.createAccount("PL10 1020 0002", "Anna", "Nowak",     2500.50);
    bank.createAccount("PL10 1020 0003", "Piotr", "Wiśniewski",  0.00);

    CLI::run(bank);

    return 0;
}