#pragma once

#include <string>
#include <unordered_map>

#include "Utility.h"

enum class Types
{
    Normal,
    Fire,
    Water,
    Grass,
    Flying,
    
    TypesLength
};

const std::unordered_map<Types, std::string> TypesTypesToStringMap = {
    { Types::Normal, "Normal" },
    { Types::Fire,   "Fire"   },
    { Types::Water,  "Water"  },
    { Types::Grass,  "Grass"  },
    { Types::Flying, "Flying" }
};

const std::unordered_map<std::string, Types> TypesStringToTypesMap = GetFlipped(TypesTypesToStringMap);
