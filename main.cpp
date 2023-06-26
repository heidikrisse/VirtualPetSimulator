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

    while (true)
    {
        std::cout << "What would you like to do?\n";
        std::cout << "1. Feed pet\n";
        std::cout << "2. Play with pet\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        int choice{};
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            my_pet.feed();
            std::cout << "\nYou fed your " << my_pet.get_type() << " " << my_pet.get_name() << ".\n";
            std::cout << "Happiness: " << my_pet.get_happiness() << "\n";
            std::cout << "Fullness: " << my_pet.get_fullness() << "\n\n";

            break;

        case 2:
            my_pet.play();
            std::cout << "\nYou played with your " << my_pet.get_type() << " " << my_pet.get_name() << ".\n";
            std::cout << "Happiness: " << my_pet.get_happiness() << "\n";
            std::cout << "Energy: " << my_pet.get_energy() << "\n\n";

            break;

        case 3:
            std::cout << "\nExiting program..\n";

            return 0;

        default:
            std::cout << "Invalid choice. Please try again.\n\n";
        }
    }
}
