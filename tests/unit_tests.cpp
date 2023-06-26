// unit_test.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/pet.h"

/* Test to check if a pet is correctly created with a name, type and
 * initial values of happiness and fullness. */
TEST_CASE("Unit-Test 1: Testing pet creation")
{
    Pet pet("Misuantti", "cat");

    CHECK(pet.get_name() == "Misuantti");
    CHECK(pet.get_type() == "cat");
    CHECK(pet.get_happiness() == 20);
    CHECK(pet.get_fullness() == 20);
}

/* Test to check if the feed() correctly increases the pet's happiness and
 * fullness:
 * -    Feeding the pet once should increase happiness by 10% and fullness by
 *      20%. */
TEST_CASE("Unit-Test 2: Testing pet feeding")
{
    Pet pet("Misuantti", "cat");

    pet.feed();

    CHECK(pet.get_happiness() == 30);
    CHECK(pet.get_fullness() == 40);
}

/* Test to check if the feed() correctly handles the maximum limit for
 * fullness:
 * -    Feeding the pet 10x should reach the maximum fullness. */
TEST_CASE("Unit-Test 3: Testing pet maximum fullness limit")
{
    Pet pet("Misuantti", "cat");

    for (int i{0}; i < 10; ++i)
        pet.feed();

    CHECK(pet.get_fullness() == 100); // Fullness should not exceed 100%
}

/* Test to check if the feed() correctly handles the maximum limit for
 * happiness:
 * -    Feeding the pet 20x should reach the maximum happiness. */
TEST_CASE("Unit-Test 4: Testing pet maximum happiness limit")
{
    Pet pet("Misuantti", "cat");

    for (int i{0}; i < 20; ++i)
        pet.feed();

    CHECK(pet.get_happiness() == 100); // Happiness should not exceed 100%
}
