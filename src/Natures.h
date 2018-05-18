#pragma once

#include <map>
#include <vector>

enum class Natures
{
    Adamant,
    Bashful,
    Bold,
    Brave,
    Calm,
    Careful,
    Docile,
    Gentle,
    Hardy,
    Hasty,
    Impish,
    Jolly,
    Lax,
    Lonely,
    Mild,
    Modest,
    Naive,
    Naughty,
    Quiet,
    Quirky,
    Rash,
    Relaxed,
    Sassy,
    Serious,
    Timid,
    
    NaturesLength
};

const std::map<Natures, std::string> NaturesTranslations = {
    { Natures::Adamant, "Adamant" },
    { Natures::Bashful, "Bashful" },
    { Natures::Bold,    "Bold"    },
    { Natures::Brave,   "Brave"   },
    { Natures::Calm,    "Calm"    },
    { Natures::Careful, "Careful" },
    { Natures::Docile,  "Docile"  },
    { Natures::Gentle,  "Gentle"  },
    { Natures::Hardy,   "Hardy"   },
    { Natures::Hasty,   "Hasty"   },
    { Natures::Impish,  "Impish"  },
    { Natures::Jolly,   "Jolly"   },
    { Natures::Lax,     "Lax"     },
    { Natures::Lonely,  "Lonely"  },
    { Natures::Mild,    "Mild"    },
    { Natures::Modest,  "Modest"  },
    { Natures::Naive,   "Naive"   },
    { Natures::Naughty, "Naughty" },
    { Natures::Quiet,   "Quiet"   },
    { Natures::Quirky,  "Quirky"  },
    { Natures::Rash,    "Rash"    },
    { Natures::Relaxed, "Relaxed" },
    { Natures::Sassy,   "Sassy"   },
    { Natures::Serious, "Serious" },
    { Natures::Timid,   "Timid"   }
};

const std::vector<Natures> NaturesThatRaiseAttack = {
    Natures::Lonely,
    Natures::Adamant,
    Natures::Naughty,
    Natures::Brave
};

const std::vector<Natures> NaturesThatLowerAttack = {
    Natures::Bold,
    Natures::Modest,
    Natures::Calm,
    Natures::Timid
};

const std::vector<Natures> NaturesThatRaiseDefense = {
    Natures::Bold,
    Natures::Impish,
    Natures::Lax,
    Natures::Relaxed
};

const std::vector<Natures> NaturesThatLowerDefense = {
    Natures::Lonely,
    Natures::Mild,
    Natures::Gentle,
    Natures::Hasty
};

const std::vector<Natures> NaturesThatRaiseSpecialAttack = {
    Natures::Modest,
    Natures::Mild,
    Natures::Rash,
    Natures::Quiet
};

const std::vector<Natures> NaturesThatLowerSpecialAttack = {
    Natures::Adamant,
    Natures::Impish,
    Natures::Careful,
    Natures::Jolly
};

const std::vector<Natures> NaturesThatRaiseSpecialDefense = {
    Natures::Calm,
    Natures::Gentle,
    Natures::Careful,
    Natures::Sassy
};

const std::vector<Natures> NaturesThatLowerSpecialDefense = {
    Natures::Naughty,
    Natures::Lax,
    Natures::Rash,
    Natures::Naive
};

const std::vector<Natures> NaturesThatRaiseSpeed = {
    Natures::Timid,
    Natures::Hasty,
    Natures::Jolly,
    Natures::Naive
};

const std::vector<Natures> NaturesThatLowerSpeed = {
    Natures::Brave,
    Natures::Relaxed,
    Natures::Quiet,
    Natures::Sassy
};
