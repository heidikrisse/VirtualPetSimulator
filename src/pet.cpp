// pet.cpp
#include "../include/pet.h"

Pet::Pet(const std::string &name, const std::string &type)
    : name(name), type(type) {}

std::string Pet::get_name() const
{
    return name;
}

std::string Pet::get_type() const
{
    return type;
}
