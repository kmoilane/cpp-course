#include "../includes/entity.hpp"
#include <cassert>
#include <iostream>

void Entity::set_union(const int value) {
    id = value;
    tag = Tag::robot;
}

void Entity::set_union(const char value) {
    letter = value;
    tag = Tag::human;
}

void Entity::set_union(const double value) {
    wavelength = value;
    tag = Tag::alien;
}

int& Entity::get_id() {
    assert(tag == Tag::robot && "ERROR: Entity is not robot");
    return id;
}

char& Entity::get_letter() {
    assert(tag == Tag::human && "ERROR: Entity is not human");
    return letter;
}

double& Entity::get_wavelength() {
    assert(tag == Tag::alien && "ERROR: Entity is not alien");
    return wavelength;
}

Tag& Entity::current_type() {
    return tag;
}

const int& Entity::get_id() const {
    assert(tag == Tag::robot && "ERROR: Entity is not robot");
    return id;
}

const char& Entity::get_letter() const {
    assert(tag == Tag::human && "ERROR: Entity is not human");
    return letter;
}

const double& Entity::get_wavelength() const {
    assert(tag == Tag::alien && "ERROR: Entity is not alien");
    return wavelength;
}

const Tag& Entity::current_type() const {
    return tag;
}

void Entity::print_union_type() const noexcept
{
    switch (tag)
    {
        case Tag::robot: {
            std::cout << "robot";
            break;
        }
        case Tag::human: {
            std::cout << "human";
            break;
        }
        case Tag::alien: {
            std::cout << "alien";
            break;
        }
    }
}

void Entity::print_union_value() const noexcept
{
    switch (tag)
    {
        case Tag::robot: {
            std::cout << Entity::get_id();
            break;
        }
        case Tag::human: {
            std::cout << Entity::get_letter();
            break;
        }
        case Tag::alien: {
            std::cout << Entity::get_wavelength();
            break;
        }
    }
}
