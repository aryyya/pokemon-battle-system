#include <fstream>
#include <iostream>
#include <iterator>

#include "Pokedex.h"
#include "Pokemon.h"

#include <nlohmann/json.hpp>

Pokedex::Pokedex(const std::string path)
{
    const std::string Data = LoadData(path);
    nlohmann::json DataJson = nlohmann::json::parse(Data);

    for (auto Entry : DataJson) {
        Pokemon Pokemon_(
            Entry["Name"],
            Type::Fire,
            Entry["Health Points"],
            Entry["Attack"],
            Entry["Defense"],
            Entry["Special Attack"],
            Entry["Special Defense"],
            Entry["Speed"]);
        PokemonDatabase.insert(std::pair<std::string, Pokemon>(Pokemon_.GetName(), Pokemon_));
    }
}

Pokemon Pokedex::Get(const std::string PokemonName)
{
    return PokemonDatabase.at(PokemonName);
}

std::string Pokedex::LoadData(const std::string path)
{
    std::ifstream Stream(path);
    std::string Data{std::istreambuf_iterator<char>(Stream), std::istreambuf_iterator<char>()};
    return Data;
}
