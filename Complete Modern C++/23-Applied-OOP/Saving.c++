//
// Created by Vincent Morin on 2022-01-03.
//

#include "Saving.h"

Saving::Saving(const std::string &name, float balance, float rate) : Account(name, balance), m_Rate(rate) {

}

Saving::~Saving() {

}

float Saving::GetInterestRate() const {
    return m_Rate;
}

void Saving::AccumulateInterest() {
    m_Balance += (m_Balance * m_Rate);
}
