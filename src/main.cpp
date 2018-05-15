#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "Battle.h"
#include "Pokedex.h"
#include "Pokemon.h"
#include "Type.h"

int main()
{
    std::srand(std::time(0));

    Pokedex Pokedex("Pokedex.json");
    Pokemon Pokemon1 = Pokedex.Get("Rowlet");
    Pokemon Pokemon2 = Pokedex.Get("Litten");
    Pokemon Pokemon3 = Pokedex.Get("Popplio");

    std::vector<Pokemon*> Pokemons = {
        &Pokemon1,
        &Pokemon2,
        &Pokemon3 };

    for (Pokemon* Pokemon : Pokemons)
    {
        Pokemon->SetLevel(100);
    }
    
    for (const Pokemon* Pokemon : Pokemons)
    {
        std::cout << Pokemon->ToString() << "\n";
    }
}
