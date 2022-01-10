//
// Created by Vincent Morin on 2022-01-03.
//

#ifndef INC_23_APPLIED_OOP_SAVING_H
#define INC_23_APPLIED_OOP_SAVING_H

#include "Account.h"

class Saving : public Account {
float m_Rate;
public:
    Saving(const std::string& name, float balance, float rate);
    ~Saving() override;

    float GetInterestRate() const override;
    void AccumulateInterest() override;

};


#endif //INC_23_APPLIED_OOP_SAVING_H
