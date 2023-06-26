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

void Pet::feed()
{
    happiness += 10;
    if (happiness > MAX_HAPPINESS)
    {
        happiness = MAX_HAPPINESS;
    }

    fullness += 20;
    if (fullness > MAX_FULLNESS)
    {
        fullness = MAX_FULLNESS;
    }
}

int Pet::get_happiness() const
{
    return happiness;
}

int Pet::get_fullness() const
{
    return fullness;
}
