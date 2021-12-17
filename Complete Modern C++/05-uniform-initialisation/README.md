# Uniform initialization
    int a1; // Uninitialized
    int a2 = 0; // Copy initialization
    int a3(5); //Direct initialization
    std::string s1;
    std::string s2("C++"); //Direct initialization

    char d1[8]; //Uninitialized
    char d2[8] = {'\0'};
    char d3[8] = {'a', 'b', 'c', 'd'}; // Aggregate initialization
    char d4[8] = {"abcd"};

    int b1{}; // Value initialization
    int b3{5}; // Direct initializationm

    int b2(); //Most vexing parse  (we declared a funtion here)
    
    char e1[8]{}; // Automaticaly initialize the array with default value 0

# All initialisation
1. Value initialization => T obj{};
2. Direct initialization => T obj{v};
3. Copy initialization => T obj = v;

Uniform syntax for all types :)