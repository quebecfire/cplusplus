//
// Created by Vincent Morin on 2021-12-16.
//

#include <iostream>

int main() {
    char buff[512] ;
    std::cout << "What is your name?" << std::endl;
    std::cin.getline(buff, 64, '\n') ;
    std::cout << "Your name is : " << buff << std::endl ;
}