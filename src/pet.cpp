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
    happiness += 10; // happiness increases by 10%
    if (happiness > MAX_HAPPINESS)
    {
        happiness = MAX_HAPPINESS;
    }

    fullness += 20; // fullness increases by 20%
    if (fullness > MAX_FULLNESS)
    {
        fullness = MAX_FULLNESS;
    }
}

void Pet::play()
{
    if (energy >= 10) // check if pet has enough energy to play
    {
        happiness += 20; // happiness increases by 20 %
        if (happiness > MAX_HAPPINESS)
        {
            happiness = MAX_HAPPINESS;
        }

        energy -= 10; // energy decreases by 10 %
    }
}

void Pet::sleep()
{
    energy += 50; // energy increases by 50%
    if (energy > MAX_ENERGY)
    {
        energy = MAX_ENERGY;
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

int Pet::get_energy() const
{
    return energy;
}
