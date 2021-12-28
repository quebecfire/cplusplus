//
// Created by Vincent Morin on 2021-12-23.
//

#include "Integer.h"

Integer::Integer() {
    m_pInt = new int{0};
}

Integer::Integer(int value) {
    m_pInt = new int{value};
}

int Integer::GetValue() const {
    return *m_pInt;
}

void Integer::SetValue(int value) {
    *m_pInt = value;
}

Integer::~Integer() {
    delete m_pInt;
    m_pInt = nullptr;
}

Integer::Integer(const Integer &object) {
    this->m_pInt = new int{*object.m_pInt};
}
