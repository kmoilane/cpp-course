#include "../includes/cfile.hpp"
#include "../includes/entity.hpp"
#include <cassert>
#include <charconv>
#include <iostream>
#include <string>

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

std::ostream& operator<<(std::ostream& os, const Entity& e)
{
    switch (e.tag)
    {
        case Tag::robot: {
            os << "Robot : " << e.id << '\n';
            break;
        }
        case Tag::human: {
            os << "Human : " << e.letter << '\n';
            break;
        }
        case Tag::alien: {
            os << "Alien : " << e.wavelength << '\n';
            break;
        }
    }
    return os;
}

bool is_float(std::string_view input)
{
    double val;
    auto [p, ec] = std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
}

bool is_int(std::string_view input)
{
    int val;
    auto [p, ec] = std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
}

Entity Entity::create(const std::string& str)
{
    if (is_int(str))
        return Entity(atoi(str.c_str()));
    else if (is_float(str))
        return Entity(atof(str.c_str()));
    else
        return Entity(str[0]);
}

std::vector<Entity> read_entities(std::string file_name)
{
    CFile file(file_name, "r");
    std::vector<Entity> entities {};
    std::string line = file.next_line();
    while (!line.empty())
    {
        entities.push_back(Entity::create(line));
        line = file.next_line();
    }
    return entities;
}

void print_entities(std::vector<Entity> entities)
{
    for (Entity entity : entities)
    {
        std::cout << entity;
    }
}
