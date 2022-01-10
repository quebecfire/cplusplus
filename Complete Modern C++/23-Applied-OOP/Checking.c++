//
// Created by Vincent Morin on 2022-01-03.
//

#include <iostream>

#include "Checking.h"

Checking::Checking(const std::string &name, float balance, float minimumBalance) : Account(name, balance),
    m_MinimumBalance(minimumBalance) {

}

Checking::~Checking() {

}

void Checking::Withdraw(float amount) {
    if (m_MinimumBalance <= (m_Balance - amount))
        Account::Withdraw(amount);
    else
        std::cout << "Insufficient balance" << std::endl;
}

float Checking::GetMinimumBalance() {
    return m_MinimumBalance;
}
