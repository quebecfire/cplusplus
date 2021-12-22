# Object Oriented Programming
1. Use objects as fundamental building blocks, rather than algorithm
2. Program is created as a collection of objects
3. Every object is an instance of some class
4. Classes are united via inheritance relationship
5. Simulate interactions of objects in real-world systems
6. Allows representation of object in problem domain as software objects
7. Decreases complexity of software systems
8. Make code reusable, extensible and maintainable

## Object Model
The object model is a set of basic principles that help us write OO programs

### Abstraction
- Focuses on important and necessary details
- Unwanted features are left out
- Represented through a class, struct, interface, union or enum

### Encapsulation
- Next step after abstraction
- Hides the implementation details of a class
- The class provides behaviour without revealing the implementation
- Object of such classes are easy to use

### Inheritances
- Represents a hierarchy of classes
- The classes are related through "is-a" relationship
- The relation is due to same behaviour of classes
- e.g. a dog is an animal
- The behaviour & its implementation is inherited by the children from the parent
- The child classes may then reuse the behaviour with the same implementation or provide a different implementation

### Composition
- Signifies relationship between objects
- Represented as "has-a" or "part-of" relationship
- Promotes reuse of objects
- e.g. car has an engine as an object

### Polymorphism
- Means different forms
- Represents common behaviour with different implementations
- Response will be different for each object, either based on its class or the arguments
  - Car can move
  - Bicycle can move
  - Person can move
  - But all differently
- Implemented through function overloading, templates & virtual functions