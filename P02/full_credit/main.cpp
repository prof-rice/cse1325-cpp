#include "pet.h"
#include <iostream>
#include <iomanip>
#include <vector>

int main() {
    std::vector<Pet> pets {
        Pet{"Freida", 3, CAT},
        Pet{"Fido", 8, DOG},
        Pet{"Fancy", 11, HORSE},
    };
    
    for(Pet p : pets) std::cout << p.to_string() << std::endl;
}
