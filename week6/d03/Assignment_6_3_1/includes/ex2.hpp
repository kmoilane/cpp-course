#ifndef EX2_HPP
#define EX2_HPP

#include <iostream>

class Animal
{
    public:
        Animal() { std::cout << "Animal is born\n"; }
        ~Animal() { std::cout << "Rest in peace animal\n"; }
        void whoami() { std::cout << "I'm an animal\n"; }
};

class Wings
{
public:
    Wings() { std::cout << "It grows 2 wings\n"; }
    ~Wings() { std::cout << "The wings fall off\n"; }
    void whoami() { std::cout << "I'm wings\n"; }
};

class Eyes
{
public:
    Eyes() { std::cout << "It grows 2 eyes\n"; }
    ~Eyes() { std::cout << "Eyes close for good\n"; }
    void whoami() { std::cout << "I'm eyes\n"; }
};

class Bird : public Animal
{
public:
    Bird() { std::cout << "The animal is bird\n"; }
    ~Bird() { std::cout << "This bird ain't flying no more\n"; }
    void whoami() { std::cout << "I'm a bird\n"; }
    Wings   wings;
    Eyes    eyes;

};

class Parrot : public Bird
{
public:
    Parrot() { std::cout << "Oh, it's a parrot\n"; }
    ~Parrot() { std::cout << "Parrot is oddly quiet\n"; }
    void whoami() { std::cout << "I'm a parrot\n"; }
};

class Dog : public Animal
{
public:
    Dog() { std::cout << "The animal is dog\n"; }
    ~Dog() { std::cout << "Dog is done barking\n"; }
    void whoami() { std::cout << "I'm a dog\n"; }
    Eyes    eyes;

};

#endif
