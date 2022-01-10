//
// Created by Vincent Morin on 2021-12-30.
//

#ifndef INC_21_ASSIGNMENTS_STRINGCONVERTER_H
#define INC_21_ASSIGNMENTS_STRINGCONVERTER_H

#include <string>
#include <utility>

enum class Case{SENSITIVE, INSENSITIVE};

class StringConverter {
    std::string m_String;
public:
    explicit StringConverter(std::string s): m_String{std::move(s)}{}
    std::string ToUpper() const;
    std::string ToLower() const;

    size_t Find(const std::string &search_string,  //The string to search for
            Case searchCase = Case::INSENSITIVE) const;

};


#endif //INC_21_ASSIGNMENTS_STRINGCONVERTER_H
