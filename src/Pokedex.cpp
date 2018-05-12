#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

#include "Pokedex.h"
#include "Pokemon.h"
#include "Type.h"

#include <nlohmann/json.hpp>

Type GetType(const std::string TypeString)
{
    return Type(TypeString);
}

Pokedex::Pokedex(const std::string path)
{
    const std::string Data = LoadData(path);
    nlohmann::json DataJson = nlohmann::json::parse(Data);

    for (auto Entry : DataJson)
    {
        auto TypeStrings = Entry["Types"];
        std::vector<Type> Types;
        Types.resize(TypeStrings.size());
        std::transform(TypeStrings.begin(), TypeStrings.end(), Types.begin(), GetType);

        Pokemon Pokemon_(
            Entry["Name"],
            Types,
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
