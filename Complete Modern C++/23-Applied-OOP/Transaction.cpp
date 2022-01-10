//
// Created by Vincent Morin on 2022-01-03.
//

#include <iostream>
#include <typeinfo>

#include "Transaction.h"
#include "Checking.h"

void Transact(Account* pAccount) {
    std::cout << "Transaction started" << std::endl;
    std::cout << "Initial balance: " << pAccount->GetBalance() <<  std::endl;
    pAccount->Deposit(120);
    pAccount->AccumulateInterest();

    const std::type_info& ti = typeid(*pAccount); // Evaluated at run time for user defined type with  a virtual function and at compile time if not
    if (ti == typeid(Checking)) {
        auto pChecking = dynamic_cast<Checking*>(pAccount);
        std::cout << pChecking->GetMinimumBalance() << std::endl;
    }

    // Or we could try dynamic cast :) and check for nullptr instead of the typeid mechanism
    auto pChecking = dynamic_cast<Checking*>(pAccount);
    if (nullptr != pChecking)
        std::cout << pChecking->GetMinimumBalance() << std::endl;
    pAccount->Withdraw(170);
    std::cout << "Interest rate: " << pAccount->GetInterestRate() <<  std::endl;
    std::cout << "Final balance: " << pAccount->GetBalance() << std::endl;
}