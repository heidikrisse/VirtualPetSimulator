# VirtualPetSimulator

Virtual Pet Simulator is an application that will simulate taking care 
of a virtual pet.

# Features

You can
* Create a new pet with a name and type you choose
* Feed the pet, which increases the pet's happiness and fullness.
* Play with the pet, which increases the pet's happiness but decreases it's energy
* Put the pet to sleep, which increases its energy

# Build project

1. Clone the repository:
```bash
$ git clone https://github.com/yourusername/VirtualPetSimulator.git
```

2. Move into the VirtualPetSimulator directory and create a new build 
   directory, and move into there:
```bash
$ cd VirtualPetSimulator
$ mkdir build
$ cd build
```

3. Run cmake and make to build the project:
```bash
$ cmake ..
$ make
```

4. Run the VirtualPetSimulator:
```bash
$ ./VirtualPetSimulator

```

# Unit-testing

This VirtualPetSimulator application uses the doctest library for unit testing.

1. To set up doctest, run the following command:
```bash
$ cd ..
$ cd include
$ sudo curl https://raw.githubusercontent.com/doctest/doctest/master/doctest/doctest.h -o doctest.h

```

2. Run the unit-tests from the tests-directory:
```bash
$ cd tests
$ ./unit_tests_results

```


