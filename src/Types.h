#pragma once

#include <map>
#include <string>

enum class Types
{
    Normal,
    Fire,
    Water,
    Grass,
    Flying,
    
    TypesLength
};

const std::map<Types, std::string> TypesTranslations = {
    { Types::Normal, "Normal" },
    { Types::Fire,   "Fire"   },
    { Types::Water,  "Water"  },
    { Types::Grass,  "Grass"  },
    { Types::Flying, "Flying" }
};
