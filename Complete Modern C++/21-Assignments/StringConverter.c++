//
// Created by Vincent Morin on 2021-12-30.
//

#include "StringConverter.h"

std::string StringConverter::ToUpper() const {
    std::string temp{};

    for (auto c : m_String) {
        temp += toupper(c);
    }
    return temp;
}

std::string StringConverter::ToLower() const {
    return std::string();
}

size_t StringConverter::Find(const std::string &search_string, Case searchCase) const {
    std::string temp = m_String;
    std::string search = search_string;

    if (searchCase == Case::INSENSITIVE) {
        for (auto& c:temp) {
            c = tolower(c);
        }
        for (auto& c:search) {
            c = tolower(c);
        }
    }

    return temp.find(search);;
}
