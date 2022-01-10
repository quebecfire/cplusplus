//
// Created by Vincent Morin on 2022-01-05.
//

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int main() {
    using namespace std::filesystem;
    std::cout << current_path().parent_path() << std::endl;
    path source(current_path().parent_path());
    source /= "main.c++";

    path dest(current_path().parent_path());
    dest /= "Copy.cpp";

    std::ifstream  input{source};

    if (!input) {
        std::cout <<  "Source file not found" << std::endl;
        return -1;
    }
    std::ofstream output{dest};


    std::string line;
    while (!std::getline(input, line).eof()) {
        output << line << std::endl;
    }
    input.close();
    output.close();
    return 0;
