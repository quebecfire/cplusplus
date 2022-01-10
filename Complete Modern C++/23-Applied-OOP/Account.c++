//
// Created by Vincent Morin on 2022-01-03.
//

#include <iostream>

#include "Account.h"

int Account::s_ANGenerator = 1000;

const std::string Account::GetName() const {
    return m_Name;
}

float Account::GetBalance() const {
    return m_Balance;
}

int Account::GetAccountNo() const {
    return m_AccNo;
}

void Account::AccumulateInterest() {

}

void Account::Withdraw(float amount) {
    if (amount < m_Balance) {
        m_Balance -= amount;
        std::cout << "Withdrawal of " << amount << " is a success" << std::endl;
    }
    else
        std::cout << "Insufficient balance" << std::endl;
}

void Account::Deposit(float amount) {
    if (amount > 0) {
        m_Balance += amount;
        std::cout << "Deposit of " << amount << " is a success" << std::endl;
    }
    else {
        std::cout << "Deposit amount need to be higher than 0" << std::endl;
    }
}

float Account::GetInterestRate() const {
    return 0;
}

Account::Account(const std::string &name, float balance) :
m_Name(name), m_Balance(balance), m_AccNo(++s_ANGenerator){

}

Account::~Account() {

}
