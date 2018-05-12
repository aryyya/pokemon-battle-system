#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Battle.h"
#include "Pokedex.h"
#include "Pokemon.h"
#include "Type.h"

int main()
{
    std::srand(std::time(0));

    Pokedex Pokedex("Pokedex.json");

    std::cout << Pokedex.Get("Rowlet").ToString() << "\n";
    std::cout << Pokedex.Get("Litten").ToString() << "\n";
    std::cout << Pokedex.Get("Popplio").ToString() << "\n";

    /*

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

    */
}
