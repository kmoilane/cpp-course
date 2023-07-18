# Assignment 6.2.3

We are going to make our first improvements upon our ex 6.1.2 class.
(I'll call it Object for brevity from here on)

Create constructor overloads to the class to make conversions from integer,
string / char and
floating point value into our Object type.  After this e.g. this should work:

```c++
Object a(42);  // stores integer, sets the state accordingly
Object b("BlahBlah"); // stores initial (char), sets the state
Object c(5.28); // stores double...
```

Think about do we need a destructor here to clean up after ourselves,
and why /why not?

(optional) Try adding `explicit` specifier the constructors
and check how the usage of the constructors differs afterwards.
Think about when you would want to use it and when not.
