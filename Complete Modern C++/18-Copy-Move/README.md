# Copy & Move Semantics

## Copy
- Copy is implemented through copy constructor
- Copy of the object state is created
- Wasteful in case copy is created from a temporary
- Instead, the state can be moved from the source object
- Implemented through move semantics

### Copy Semantics

It is important to understand that a copy semantics ALWAYS implies allocation of new memory.
And this has a cost.

### Move Semantics

The move semantics allow resources stealing from temporaries.
It's good to implement a move constructor for detecting temporaries
