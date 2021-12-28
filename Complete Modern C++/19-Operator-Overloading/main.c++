//
// Created by Vincent Morin on 2021-12-28.
//

#include <iostream>
#include "Integer.h"


// Let's implement the RAII proposed by the creator of C++

class IntPtr {
    Integer *m_p;
public:
    IntPtr(Integer* p) : m_p(p) {}
    ~IntPtr() {
        delete m_p;
    }

    Integer* operator ->() {
        return m_p;
    }

    Integer& operator *() {
        return *m_p;
    }
};

void CreateInteger1() {
    auto p = new Integer;
    p->SetValue(1);
    std::cout << p->GetValue() << std::endl;
}

void CreateInteger2() {
    IntPtr p = new Integer;
    p->SetValue(2); // Example of the -> operator on the IntPtr class
    std::cout << (*p).GetValue() << std::endl; // Example of the * operator on the IntPtr class
}

int main() {
    std::cout<< "Hello World!" << std::endl ;

    // RAII Example
//    CreateInteger1(); // Here we can see that no destructor is called. That is normal, we have an object on the heap that lifetime isn't related to the scope. And we didn't call delete
//    CreateInteger2(); // Here we can realise that since we have a local scope object, IntPtr, the destructor was called at the end of the scope.

    Integer a{10}, b{5}, c{};
    c = a + b;

    std:: cout << c.GetValue() << std::endl ;
    ++c; // Pre increment operator

    std:: cout << (c++).GetValue() << std::endl ;
    std:: cout << c.GetValue() << std::endl ;
    return 0;
}
