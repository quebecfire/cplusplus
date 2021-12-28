//
// Created by Vincent Morin on 2021-12-25.
//

#ifndef INC_15_STRUCTURE_INTEGER_H
#define INC_15_STRUCTURE_INTEGER_H


class Integer {
    int* m_pInt;

public:

    // Default constructor
    Integer();
    // Parameterized constructor
    Integer(int value);
    // Copy constructor
    Integer(const Integer &object);
    // Move constructor
    Integer(Integer&& obj) noexcept ; // R-value reference
    // Copy assignment
    Integer& operator=(const Integer& obj);
    // Move assignment
    Integer& operator=(Integer&& obj);

    ~Integer();
    int GetValue() const; // Will produce a compiler warning to indicate the return value must be used.
    void SetValue(int value);
};


#endif //INC_15_STRUCTURE_INTEGER_H
