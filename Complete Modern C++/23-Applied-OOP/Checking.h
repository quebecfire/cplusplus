//
// Created by Vincent Morin on 2022-01-03.
//

#ifndef INC_23_APPLIED_OOP_CHECKING_H
#define INC_23_APPLIED_OOP_CHECKING_H

#include "Account.h"
class Checking : public Account{
    float m_MinimumBalance;
public:
    using Account::Account; // Inherit the base constructor
    Checking(const std::string &name, float balance,float minimumBalance);
    ~Checking() override;

    float GetMinimumBalance();
    void Withdraw(float amount) override;
};


#endif //INC_23_APPLIED_OOP_CHECKING_H
