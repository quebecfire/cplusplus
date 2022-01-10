//
// Created by Vincent Morin on 2022-01-03.
//

#include <iostream>

#include "Checking.h"
#include "Saving.h"
#include "Transaction.h"

int main() {
    Saving saving("Saving", 500, 0.05f);
    Checking checking("Checking", 1000, 50);
    Transact(&checking);
    std::cout << "Minimum balance: " << checking.GetMinimumBalance() << std::endl;
    std::cout << "-----------------" << std::endl;
    Transact(&saving);
}