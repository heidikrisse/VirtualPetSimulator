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

private:
    std::string name;
    std::string type;
};

#endif // PET_H
