# C++11 and the introduction of smart pointer

The release of C++11 provided to the C++ language a lot of features, ont of the most important of those is the smarts pointer addition.

```c++
    #include <memory>
```

Unique pointer is in the standard pointer and is a class namespace. They have explicit constructor, so direct initialization is
required.

## Unique Pointer

```c++
std::unique_ptr<Integer> p(new Integer);
```

The unique pointer provide a safe to handle a dynamically created object that you don't want to allow copy of.
When the pointer reach the end of the scope it will automatically get destructed and will call to delete of the dynamic object.

p.reset() can be used to reset a nullptr.
p.get() will return the underlining pointer
```c++
 std::move(p) // can be used to move the unique pointer, but after p will be uninitialized. Don't use it.
```

## Shared Pointer

```c++
    std::shared_ptr<Integer> p(new Integer);
```

A shared pointer contain a counter that will increment every time it's shared, and decrement at each pointer destruction.
When the counter is at 0, the handled resources is deleted/release.
