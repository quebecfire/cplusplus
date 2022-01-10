//
// Created by Vincent Morin on 2021-12-30.
//

#include <iostream>
#include <initializer_list>

#include "StringConverter.h"

int main() {
    StringConverter s{"je m'appel vincent"};

    std::cout << s.ToUpper() << std::endl;

    if (s.Find("vincenT", Case::SENSITIVE) != std::string::npos) {
        std::cout << "Case::SENSITIVE -> Found" << std::endl;
    } else
        std::cout << "Case::SENSITIVE -> Not Found" << std::endl;

    if (s.Find("vincenT") != std::string::npos) {
        std::cout << "Case::INSENSITIVE -> Found" << std::endl;
    } else
        std::cout << "Case::INSENSITIVE -> Not Found" << std::endl;

    return 0;
}