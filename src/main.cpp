#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Pokemon.h"
#include "Type.h"
#include "Battle.h"

int main()
{
    std::srand(std::time(0));

    Pokemon Pokemon1(
        "Charmander", // Name
        Type::Fire,   // Type
        100,          // Health
        10,           // Attack
        10,           // Defence
        10,           // SpecialAttack
        10,           // SpecialDefense
        10);          // Speed

    Pokemon Pokemon2(
        "Squirtle",  // Name
        Type::Water, // Type
        100,         // Health
        10,          // Attack
        10,          // Defence
        10,          // SpecialAttack
        10,          // SpecialDefense
        10);         // Speed

    Pokemon Pokemon3(
        "Bulbasaur",  // Name
        Type::Grass,  // Type
        100,          // Health
        10,           // Attack
        10,           // Defence
        10,           // SpecialAttack
        10,           // SpecialDefense
        10);          // Speed

    Battle Battle(Pokemon2, Pokemon3);

    while (Pokemon1.IsAlive() && Pokemon3.IsAlive())
    {
        Battle.Round();
    }
}
