//
// Created by Vincent Morin on 2022-01-03.
//

#ifndef INC_23_APPLIED_OOP_ACCOUNT_H
#define INC_23_APPLIED_OOP_ACCOUNT_H

#include <string>

class Account {
    std::string m_Name;
    int m_AccNo;

protected:
    float m_Balance;

public:
    Account(const std::string& name, float balance);
    virtual ~Account();
    const std::string GetName() const;
    float GetBalance() const;
    int GetAccountNo() const;

    virtual void AccumulateInterest();

    virtual void Withdraw(float amount);
    void Deposit(float amount);

    virtual float GetInterestRate() const;

    static int s_ANGenerator;
};


#endif //INC_23_APPLIED_OOP_ACCOUNT_H
