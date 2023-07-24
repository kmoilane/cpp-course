# Assignment 7_1_2

Often needed container type is a 2D grid (you might've noticed already).  We are going
to create a standard library-compatible container for such an use case during the week.

Look through https://en.cppreference.com/w/cpp/named_req/Container.  You don't
need to understand everything yet (and you can completely ignore the complexity).

## Exercise 1

Create a template class for the grid.  Think about the template parameters it should have.

Look at "Types" under the requirements found in the Container specification.
Create type aliases for those for your grid class.  Think what for example 
size_type should be here?

In addition to that, we want a storage_type defined, which will be the type of 
the actual
storage we use. (e.g. an std::vector)

 

## Exercise 1.5

It is useful to create helper types if you did not do so already.  Create types 
representing
the dimensions of the grid (i.e. width & height) and position on the grid.

 

## Exercise 2

Implement accessing a grid element.  You'll need to calculate the index postion 
to the internal memory buffer for this.  Typically this is done by overloading 
the operator()or providing function at(), but C++23 finally allows using 
multidimensional subscript operator as well (operator[]), use whatever you 
prefer (or do all if you want!).

Implement a way to print the contents of the grid to the terminal.

 

## Exercise 3

Implement begin() and end(),  and their const-overloads.

 

## Exercise 4

Implement getting the current grid size, and optionally resizing the grid

 

At this point you should alrady have quite an useful grid type.  Feel
free to improve on it yourself, or try out how standard algorithms work
with it at this point.

 

(optional, should only do this if you plan to use your grid type later)
## Exercise 5

Use doctest to implement unit tests for your grid type, and implement
the remaining Container requirements.
