// pet.h
#ifndef PET_H
#define PET_H

#include <string>

class Pet
{
public:
    Pet(const std::string &name, const std::string &type);
    std::string get_name() const;
    std::string get_type() const;

    void feed();
    int get_happiness() const;
    int get_fullness() const;

private:
    std::string name;
    std::string type;

    // Initial happiness and fullness values to 20 %.
    int happiness{20};
    int fullness{20};

    // Constants for max happiness and fullness are 100%.
    const int MAX_HAPPINESS{100};
    const int MAX_FULLNESS{100};
};

#endif // PET_H
