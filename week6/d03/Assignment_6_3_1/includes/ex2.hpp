#ifndef EX2_HPP
#define EX2_HPP

#include <iostream>

class Animal
{

};

class Wings
{
public:
    void wing_count() { std::cout << "I have 2 wings\n"; }

private:

};

class Eyes
{

};

class Bird : public Animal
{
public:
    Wings   wings;
    Eyes    eyes;
private:

};

class Parrot : public Bird
{

};

class Dog : public Animal
{
public:

private:
    Eyes    eyes;
};

#endif
