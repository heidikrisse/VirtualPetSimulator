// pet.h
#ifndef PET_H
#define PET_H

#include <string>
#include <iostream>

class Pet
{
public:
    Pet(const std::string &name, const std::string &type);
    std::string get_name() const;
    std::string get_type() const;

    void feed();
    void play();
    void sleep();
    int get_happiness() const;
    int get_fullness() const;
    int get_energy() const;
    void print_current_stats();

private:
    std::string name;
    std::string type;

    // Initial happiness, fullness and energy values to 20 %.
    int happiness{20};
    int fullness{20};
    int energy{20};

    // Constants for max happiness, fullness and energy are 100%.
    const int MAX_HAPPINESS{100};
    const int MAX_FULLNESS{100};
    const int MAX_ENERGY{100};
};

#endif // PET_H
