#pragma once

#include <map>
#include <string>

#include "Pokemon.h"

class Pokedex
{
public:
    Pokedex(const std::string& path);

    Pokemon Get(const std::string& PokemonName);

private:
    std::map<std::string, Pokemon> PokemonDatabase;

    std::string LoadData(const std::string& path);
};
