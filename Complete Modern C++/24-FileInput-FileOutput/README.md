# File input & File output

## Raw String Literals

```c++
#include <iostream>
#include <string>

int main() {
    std::string filename{R"(C:\temp\newfile.txt)"};
    std::cout << filename << std::endl;
    std::string message{ R"MSG(C++ introduced filesystem API"(In c++17)")MSG"};
    std::cout << message << std::endl;
    return 0;
}
```

## The file system library (Deprecated)

```c++
#include <iostream>
#include <filesystem>

int main() {
    using namespace std::filesystem;
    path p{"/Users/vincentmorin/Repository/cplusplus/Complete Modern C++"};
    if (p.has_filename()) {
        std::cout << p.filename() << std::endl;
    }

    for (const auto& x : p) {
        std::cout << x << std::endl;
    }
    return 0;
}
```

## File I/O

- C++ provides supprot for file I/O through following classes
  - ofstream - write to an output stream
  - ifstream - read from an input stream
  - fstream - write/read stream
- Include <fstream> header
- All classes can be used for both txt & binary I/O
- Additionally, they supprot modes that decide how the file is opened and operated
- is_open() function returns a boolean indicating if a stream is open

```c++
#include <iostream>
#include <fstream>
#include <string>

void Write() {
    std::ofstream  out{"data.txt"};
    out << "Hello world" << std::endl;
    out << 10 << std::endl;
    out.close();
}

void Read() {
    std::ifstream input{"data.txt"};
    std::string message;
    std::getline(input, message);
    int value{};
    input >> value;
    input.close();
    std::cout << message << " : " << value << std::endl;
}

int main() {
    Write();
    Read();
    return 0;
}
```

### Handling error

```c++
//
// Created by Vincent Morin on 2022-01-05.
//

#include <iostream>
#include <fstream>
#include <string>

void Write() {
    std::ofstream  out{"data.txt"};
    out << "Hello world" << std::endl;
    out << 10 << std::endl;
    out.close();
}

void Read() {
    std::ifstream input{"data.txt"};
    if (!input.is_open()) { // input.is_open() is the main function to use to validate if a file was open
        std::cout << "could not open the file" << std::endl;
        return;
    }
//    if (input.fail()) { // Fail bit is set when file opening wasn't successful, it can also be used to detect opening
//        std::cout << "could not open the file" << std::endl;
//        return;
//    }
    std::string message;
    std::getline(input, message);
    int value{};
    input >> value;
    if (input.good()) {
        std::cout << "I/O operations are successfull" << std::endl;
    } else {
        std::cout << "Some I/O operations failed" << std::endl;
    }
    input >> value;
    if (input.fail() && input.eof()) { // Fail bit are set when reading from a file wasn't successful and eof bit is set when end of file is detected
        std::cout << "We reached the end of files" << std::endl;
    }
    input.clear(); // Clear all flags to default
    input.setstate(std::ios::failbit); // Set the failbit
    input.close();
    std::cout << message << " : " << value << std::endl;
}

int main() {
    Write();
    Read();
    return 0;
}
```

### Copying utility

```c++
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
}
```

### Character IO & seeking

```c++

#include <iostream>
#include <fstream>
#include <string>

void Write() {
    std::ofstream out{"test.txt"};

    if(!out) {
        std::cout << "Could not open file for writing" << std::endl;
        return;
    }
    std::string message{"c++ was invented by Bjarne"};

    for (const auto& ch : message) {
        out.put(ch);
    }
    out.seekp(5); // Move to the fifth index
    out.put('#'); // Replace the fifth index character
}

void Read() {
    std::ifstream input{"test.txt"};
    if (!input) {
        std::cout << "Source file not found" << std::endl;
        return;
     }

    std::cout << "Current position is: " << input.tellg() << std::endl;
    //input.seekg(10, std::ios::beg); // Move to the position 10 from the beginning
    std::cout << "Current position is: " << input.tellg() << std::endl;
    char ch{};
    while (input.get(ch)) {
        std::cout << ch << std::endl;
    }
}

void UsingFstream() {
    std::fstream stream{"file.txt"};
    if (!stream) {
        std::ofstream out{ "file.txt"};
        out.close();
        stream.open("file.txt");
    }
    stream << "Hello World" << std::endl;

    stream.seekg(0);
    std::string line;
    std::getline(stream, line);
    std::cout << line << std::endl;
}

int main() {
//    Write();
//    Read();
    UsingFstream();
    return 0;
}
```

### Binary I/O