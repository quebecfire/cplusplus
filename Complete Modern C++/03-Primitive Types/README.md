# Primitive Types
- Arithmetic & void
- Arithmetic -> Integral & floating point
- Integral types -> bool, char, wchar_t, char16_t, char32_t, short, int, long
- Floating point -> float & double

# Modifier
- Some primitive type can be modified using modifiers
  - signed, unsigned, short, long
- All types can be qualified with qualifiers - const, volatile, static
- All types occupy memory and can hold a range of values
  - memory requirements may change with platform
  
climits header file hold maximum value of modifiers size

cfloat header file hold all define for managing float number

# Variable Declaration
- int identifier1
- float identifier2
- A variable is also called an identifier
- Multiple variable can be declared with the same type
  - int a, b, c
- May or may not be initialized with an initializer
- Better to initialize variables during declaration to avoid bugs
- Some compilers don't allow read operation from an uninitialized variable