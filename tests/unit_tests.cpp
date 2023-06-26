// unit_test.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/pet.h"
#include <fstream>

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

/* Test to check if the play() correctly increases the pet's happiness and
 * decreases energy:
 * -    Playing with the pet once should increase happiness by 20% and decrease energy by 10%. */
TEST_CASE("Unit-Test 5: Testing pet playing")
{
    Pet pet("Misuantti", "cat");

    pet.play();

    CHECK(pet.get_happiness() == 40); // Now increases happiness by 20%
    CHECK(pet.get_energy() == 10);    // Decreases energy by 10%
}

/* Test to check if the play() correctly handles the maximum limit for
 * happiness:
 * -    Playing with the pet 5x should reach the maximum happiness. */
TEST_CASE("Unit-Test 6: Testing pet maximum happiness limit with playing")
{
    Pet pet("Misuantti", "cat");

    // To make sure the pet has enough energy to play 5x
    pet.sleep();

    for (int i{0}; i < 5; ++i)
    {
        pet.play();
    }

    CHECK(pet.get_happiness() == 100); // Happiness should not exceed 100%
}

/* Test to check if the play() correctly handles the minimum limit for
 * energy:
 * -    Playing with the pet 3x should reach the minimum energy. */
TEST_CASE("Unit-Test 7: Testing pet minimum energy limit with playing")
{
    Pet pet("Misuantti", "cat");

    for (int i{0}; i < 3; ++i)
        pet.play();

    CHECK(pet.get_energy() == 0); // Energy should not drop below 0%
}

/* Test to check if the sleep() correctly increases the pet's energy:
 * -    Putting the pet to sleep once should increase energy by 50%. */
TEST_CASE("Unit-Test 8: Testing pet sleep")
{
    Pet pet("Misuantti", "cat");

    pet.sleep();

    CHECK(pet.get_energy() == 70); // Increases energy by 50%
}

/* Test to check if the sleep() correctly handles the maximum limit for
 * energy:
 * -    Putting the pet to sleep twice should reach the maximum energy. */
TEST_CASE("Unit-Test 9: Testing pet maximum energy limit with sleep")
{
    Pet pet("Misuantti", "cat");

    for (int i{0}; i < 2; ++i)
        pet.sleep();

    CHECK(pet.get_energy() == 100); // Energy should not exceed 100%
}

// Test if the pet's state can be correctly saved and loaded from a file.
TEST_CASE("Unit-Test 10: Testing Pet State Save and Load from File")
{
    // Create a pet
    Pet original_pet("Misuantti", "cat");
    // Change its states
    original_pet.feed();
    original_pet.play();

    // Save the state of the original pet to the file
    original_pet.save_state_to_file();

    // Create a new pet and load the state from the file
    Pet loaded_pet("Unknown", "unknown");
    loaded_pet.load_state_from_file();

    // The state of the loaded pet should match the state of the original pet.
    CHECK(loaded_pet.get_name() == original_pet.get_name());
    CHECK(loaded_pet.get_type() == original_pet.get_type());
    CHECK(loaded_pet.get_happiness() == original_pet.get_happiness());
    CHECK(loaded_pet.get_fullness() == original_pet.get_fullness());
    CHECK(loaded_pet.get_energy() == original_pet.get_energy());
}
