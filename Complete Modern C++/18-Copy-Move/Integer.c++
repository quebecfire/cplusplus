//
// Created by Vincent Morin on 2021-12-25.
//

#include <iostream>

#include "Integer.h"

Integer::Integer() {
    std::cout << "Integer()" << std::endl;
    m_pInt = new int{0};
}

Integer::Integer(const Integer &object) {
    std::cout << "Integer(const Integer &object)" << std::endl;
    this->m_pInt = new int{*object.m_pInt};
}

Integer::Integer(int value) {
    std::cout << "Integer(int value)" << std::endl;
    m_pInt = new int{value};
}

int Integer::GetValue() const {
    return *m_pInt;
}

void Integer::SetValue(int value) {
    *m_pInt = value;
}

Integer::~Integer() {
    std::cout << "~Integer()" << std::endl;
    delete m_pInt;
    m_pInt = nullptr;
}

Integer::Integer(Integer &&obj) noexcept {
    std::cout << "Integer(Integer &&obj)" << std::endl;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

Integer& Integer::operator=(const Integer &obj) {
    std::cout << "operator=(const Integer &obj)" << std::endl;
    if (this == &obj) {
        return *this;
    }

    delete m_pInt;
    m_pInt = new int{*obj.m_pInt};
    return *this;
}

Integer& Integer::operator=(Integer &&obj) {
    std::cout << "operator=(Integer &&obj)" << std::endl;
    if (this == &obj) {
        return *this;
    }
    delete m_pInt;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;

    return *this;
}
