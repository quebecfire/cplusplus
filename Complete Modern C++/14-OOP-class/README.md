# OOB

## Class
- Blueprint/template/recipe
- Represents an abstraction
- Every object is instantiated
- Instance of a class
- Can have multiple instances
- Objects are independent


If no modifiers is provided, it's considered private

### Constructor
#### Default
- Constructor with no argument
- Automatically synthesized by the compiler if no user-defined exist

#### Parameterized Constructor
- Constructor that accepts one or more arguments
- Used to initialize the object with user-defined values
- Never synthesized by the compiler
- Blocks auto generation of default constructor

### Destructor
- Function that is invoked automatically when an object is destroyed
- Used for releasing resources that may have been allocated in the constructor
- Cannot be overloaded
- No arguments
- Compiler synthesized one if required