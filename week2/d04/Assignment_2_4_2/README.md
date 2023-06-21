
# Modbus communication

**Modbus is a communication protocol for connecting electronic devices,
allowing them to exchange data and be controlled by a central computer. 
In this exercise you are going to simulate a simple Modbus communication between
one master device and a 10 slave devices. All the data will be stored in and
read from files.**

## Exercise 1:

Every device has an unique id, is it master or slave device, and each slave
device has a data register with the register address and a value
for the register.

Start by creating a program that generates the devices and stores them in a
file called devices.csv (comma separated values) and another file called
registers.csv that will store the slave devices id, register address and value.
https://fi.wikipedia.org/wiki/CSVLinks

## Exercise 2:

Your program will simulate the master device reading a register from a slave
device. Specify the slave device id, and register number, the program
will then read the correct device and register, and print the register value.

## Exercise 3:

Simulate the master writing a value into a slave device's register. Specify the
id, register address and the new value. The program should update the value in
the "register.txt" file.
