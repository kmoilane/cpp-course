# Assignment 6.2.2

To demonstrate RAII, we are going to wrap some C functionality into a class of our own.
This is a common task since we often want to use C libraries and still benefit from RAII.
(And with some improvement, the end result might actually be useful to you later)

## Exercise 1

We are going to wrap C file functionality to a C++ class here.

We want a type for text files we can use to read them more easily.  Create a class that

Using C file functionality, opens a text file when instantiated
(either with a static member function, or a constructor)
Uses RAII, and cleans up after itself
Has a function to read in the next line of the text file
(optional) Has a function to print the file size
 

To open a file using C functionality, first #include <cstdio> and <cstdlib>

C uses FILE* as the type for the files.  This is a pointer, but we do
not need to concern ourselves with that too much right now.

You can open the file with e.g.
```c++
file_handle = fopen(filename, "a+");
```
or

```c++
file_handle = fopen(filename, "r");
```

There is a really nice flowchart what the latter argument means at
https://stackoverflow.com/questions/56381066/how-to-open-a-file-in-both-read-and-append-mode-at-the-same-time-in-one-variable

The file handle we have is a resource, and it needs to be released. 
The releasing is done by e.g.

```c++
fclose(file_handle);
```

 

To read data until next line, you can read a byte at a time,
until you get either EOF (end of file) or '\n' (end of line).

```c++
int symbol; // we want int to handle EOF
while((symbol = std::fgetc(handle)) != EOF)
// symbol holds single read character here, static_cast<char>(symbol) gives you the letter, and you
// can check for symbol == '\n' to recognize end of lines.
```
