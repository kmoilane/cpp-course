# Assignment 10.2.1 (Group task!)

Lets say we have a system of 5 planets of same mass (for some reason there's no
star).
We need to find out their period, so the time it takes for all of them to be
back at their starting positions.
We concider a 3D system.

The planets start at positions

{0, 5, 2}, {-10, 7, -94}, {6042, 4, 8}, {-42, 55, 92} and {0, -54189072, 0}

Each planet has zero velocity at start.

Simulate the motion in time steps.  During each time step each of the planets'
gravity is applied. This increases or decreases the velocity of
the bodies by exactly +1 or -1.

(e.g. if planet 1 has x coordinate smaller than planet 2, then the velocity of
planet 1 increases and planet 2 decreases in x-direction)

After the gravity is applied, each planet's coordinates change according to
their velocity.
Then, next iteration starts with the new values.

- This kind of problems usually take way too long to brute force (this one can be
done, since the numbers happen to be nice, you can try changing the numbers
around to see how much it affects the solution time)
- Think about how can you split this task into smaller tasks so that they do not
affect each other.
- Launch each of the smaller tasks in a different thread
- Combine the result to get total period
 

This is absolutely not a trivial task, so feel free to ask for help if you feel
like you get stuck.
And don't worry if you don't get it fully done.
