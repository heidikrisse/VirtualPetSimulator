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

void Pet::print_current_stats()
{
    std::cout << "Your " << type << " " << name << "'s current stats:\n";
    std::cout << "Happiness: " << happiness << "%\n";
    std::cout << "Fullness: " << fullness << "%\n";
    std::cout << "Energy: " << energy << "%\n";
    std::cout << "------------------\n\n";
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

    std::cout << "\nYou fed your " << type << " " << name << ".\n\n";

    print_current_stats();
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

    std::cout << "\nYou played with your " << type << " " << name << ".\n\n";

    print_current_stats();
}

void Pet::sleep()
{
    energy += 50; // energy increases by 50%
    if (energy > MAX_ENERGY)
    {
        energy = MAX_ENERGY;
    }

    // Fullness and happiness decrease by 10%
    fullness -= 10;
    if (fullness < 0)
    {
        fullness = 0;
    }

    happiness -= 10;
    if (happiness < 0)
    {
        happiness = 0;
    }

    std::cout << "\nYour " << type << " " << name << " has slept and gained more energy.\n\n";

    print_current_stats();
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
