# Assignment 3_1_2

## Virtual Weather Station

Your task is to create a virtual weather station. The program should
handle any exceptions that may occur during runtime. 

Handle various aspects like temperature, humidity,
wind speed and atmospheric pressure.

Generate weather data via a function simulating changes in weather over time.
Make sure the data changes in a way that's somewhat realistic.
So the temperature should not jump from +20C to -20C.

Implement exception handling. If data generated is out of logical range for
example the temperature is less than -273.15C or humidity is over 100%. 

Log data in files. Handle any file-related exceptions
like not being able to open the file. 

The console applications should be able to show logs and current weather.
For testing purposes you can add a function
that allows you to manually add weather readings.
