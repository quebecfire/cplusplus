//
// Created by Vincent Morin on 2021-12-23.
//

#ifndef INC_15_STRUCTURE_INTEGER_H
#define INC_15_STRUCTURE_INTEGER_H


class Integer {
    int* m_pInt;

public:
    Integer();
    Integer(Integer const &object);
    explicit Integer(int value);
    [[maybe_unused]] Integer(float value) = delete; // Since c++17m we can tell compiler this will not be used and shutdown warning.
    ~Integer();
    [[nodiscard]] int GetValue() const; // Will produce a compiler warning to indicate the return value must be used.
    void SetValue(int value);
};


#endif //INC_15_STRUCTURE_INTEGER_H
