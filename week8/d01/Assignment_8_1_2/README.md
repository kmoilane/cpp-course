# Assignment 8_1_2

In our animal exercise, we couldn't create a vector of our animal objects.
Now, with smart pointers we have tools to make this happen.

Manually create a text file that contains comma-separated an animal
type (species) and it's name in every line.  e.g.
```
parrot, Joe
dog, Lassie
cat, Lucifer
```

## Exercise 1

Create a vector of unique_ptrs to animal base class, and read the file and
add the animals to the vector.  If the animal species matches a class for the
species, create a pointer to that type of animal, otherwise create a
general animal pointer.

Test your program by printing the contents of the vector.

Think about why this needed to be done with virtual classes instead of using
static polymorphism, and about the tradeoffs compared to using e.g. tagged union
here.
