# Assignment_10_1_2

It is common to separate input thread from functionality, let's see a bit how that works.

## Exercise 1

Create a log, a vector of strings is a decent choice for the storage.
Knowing it will be accessed from multiple threads, think a bit how you want to handle it.

Create a function to read user input until user writes "quit"
(or some other way for the user to gracefully exit) Add the read input to the log.

Create a function to add a message to the log every second.
(e.g. "one second passed" or "program has been running for n seconds")

Make the program print the log if user input matches some command e.g. "log"

Launch both functions in separate threads, try it out.

## Exercise 2

Implement functionality so the second loop exits gracefully if the user decided to exit
