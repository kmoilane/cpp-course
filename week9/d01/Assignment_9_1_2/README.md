# Assignment_9_1_2


This is more about treating functions as template arguments.  It can be useful every now and then to pass function directly as a template argument.  You won't need <functional> for these.

Helpful code for exercise:

```c++
template <typename R, typename... Args>
class caller
{
    caller(R(*)(Args... args)) { ... }
}

caller c( /* function to check */ );
```

## Exercise 1a

Create a template class, that takes an arbitrary function as its template parameter.  Use the constructor to deduce the template types so user doesn't have to provide them.

## Exercise 1b

Save the information about function return type (via using) and function arity (number of arguments) in the class.  (This requires you to template the return type and function parameters separately)

## Exercise 1c

Create a function to test your class with.  Use decltype to printing out infomation contained without manually entering the template parameters.

## Exercise 2 (Optional)

Figure out a way to store the function argument types.
(hint: It's quite simple but needs a bit of lateral thinking)
