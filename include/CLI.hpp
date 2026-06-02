#pragma once

#include "Bank.hpp"

namespace CLI {
    int showMainMenu();

    void handleCreateAccount(Bank& bank);

    void handleDeposit(Bank& bank);

    void handleWithdraw(Bank& bank);

    void handleShowAccount(Bank& bank);

    void handleListAccounts(const Bank& bank);

    void run(Bank& bank);
}