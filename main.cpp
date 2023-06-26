// main.cpp
#include "include/pet.h"
#include <iostream>
#include <string>

int main()
{
    std::string pet_name{};
    std::string pet_type{};

    std::cout << "Enter the type of your pet: ";
    std::getline(std::cin, pet_type);

    std::cout << "Enter the name of your pet: ";
    std::getline(std::cin, pet_name);

    Pet my_pet(pet_name, pet_type);

    std::cout << "Created a " << my_pet.get_type() << " named " << my_pet.get_name() << ".\n";

    return 0;
}
