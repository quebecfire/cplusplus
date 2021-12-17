//
// Created by Vincent Morin on 2021-12-17.
//

//Try to modify x1 & x2 and see the compilation output
int x{5};
const int MAX{12};
int &ref_x1{x};
const int &ref_x2{x};

//Try to modify the pointer and the pointee value
const int *ptr1{&x}; // Possible to modify the ptr, but not the pointee value
int *const ptr2{&x}; // Possible to modify the value of the pointee, but not the ptr
const int *const ptr3{&x}; // Can't modify the ptr and can't modify the pointee

// Find which declarations are valid, if invalid, correct the declaration
const int *ptr5{&MAX}; // This is a valid declarations, because we are pointing to the same type as the pointer
const int *ptr4{&MAX}; //int *ptr4{&MAX};  // This is not a valid declarations because the pointee type is const

const int &r1{ref_x1}; // This is a valid reference declaration to a int, here were are specifying that we don't want the reference to modify the value and no more memory is allocated here
const int &ref2{ref_x2}; //int &r2{ref_x2}; // This is not a valid reference declaration to a const int, we would need to declaration it const.

const int * &p_ref1{ptr1};
const int *const &pref_2{ptr2};