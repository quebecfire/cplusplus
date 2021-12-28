# Constructor

## Copy Constructor

- Creates copy of the object's state in another object
- User defined implementation is required for pointer members.
- If a copy constructor isn't defined, the compiler will automatically generate one.
  - But this could cause some problems, with pointer member.

Here I provided a wrapper around the integer primitive class that will hold the value on the heap to give an example.

## Delegating Constructor

- Allows a constructor to invoke another constructor
- Replacement for common initialization
- Reduces duplicate initialization in multiple constructors

Car class is implementing the delegate constructor concept.
