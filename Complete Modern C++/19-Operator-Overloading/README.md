# Operator Overloading

## Intro
- Custom implementation for primitive operators
- Allows usage of user-defined objects in mathematical expressions
- Overloaded as functions but provides convenient notation
- Implemented as member or global functions
- Require usage of the operator keyword

```c++
    <ret> operator <#>(<argument>)
```

- As global functions, the overloading require sam no. of arguments as the operands
- As members functions, one operand is passed ad argument and the other through this pointer
  - Binary operator will require only one explicit argument
  - Unary operator will not require any explicit argument

```c++
    Integer operator +(const Integer&, const Integer&) // Global function
    Integer Integer::operator +(const Integer&) // Member fundtion
```

### Increment operator
#### Pre Increment

Pre increment operator is more efficient than post increment, because it doesn't require temporary

```c++
  Integer& Integer::operator++() {
      ++(*m_pInt);
      return *this;
  }
```

#### Post Increment
A post increment operator has the same syntax, but require the writer to define an int argument to help the compiler distinguish the implementation and declarion

```c++
  Integer Integer::operator++(int) {
      Integer temp{*this};
      ++(*m_pInt);
      return temp;
  }
```

### << (insertion operator) and >> operator

These 2 operators are defined in the ostream class, and we can't touch this class.
They then need to be defined globally.

```c++
  std::ostream& operator <<(std::ostream& out, const Integer& a) {
    out << a.GetValue();
    return out;
}
```

```c++
  std::istream& operator >>(std::istream& input, Integer& a) {
    int x;
    input >> x
    a.SetValue(x);
    return input;
}
```

### The () operator

```c++
  void Integer::operator()(){
    std::cout << *m_pInt << std::endl;
}
```

## General Rules
- Associativity, precedence & parity (operand count) does not change
- Operator functions should be non-static
  - except for new & delete (very special alocators :P)
- One argument should be user defined type
- Global overload if first operand is primitive type
- Not all operators can be overloaded
  - . ?: .* sizeof
- Cannot define new operators
- Overloaded for conventional behaviour only