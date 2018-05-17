#include <string>

#include "Nature.h"
#include "Natures.h"
#include "Pokemon.h"
#include "Stats.h"
#include "Utility.h"

// CONSTRUCTORS:

Nature::Nature()
{
    this->Nature_ = static_cast<Natures>(GetRandomInt(0, static_cast<int>(Natures::NaturesLength) - 2));
}

Nature::Nature(const Natures& Nature)
{
    this->Nature_ = Nature;
}

// OTHERS:

std::string Nature::ToString() const
{
    switch (Nature_)
    {
        case Natures::Adamant:       return "Adamant";
        case Natures::Bashful:       return "Bashful";
        case Natures::Bold:          return "Bold";
        case Natures::Brave:         return "Brave";
        case Natures::Calm:          return "Calm";
        case Natures::Careful:       return "Careful";
        case Natures::Docile:        return "Docile";
        case Natures::Gentle:        return "Gentle";
        case Natures::Hardy:         return "Hardy";
        case Natures::Hasty:         return "Hasty";
        case Natures::Impish:        return "Impish";
        case Natures::Jolly:         return "Jolly";
        case Natures::Lax:           return "Lax";
        case Natures::Lonely:        return "Lonely";
        case Natures::Mild:          return "Mild";
        case Natures::Modest:        return "Modest";
        case Natures::Naive:         return "Naive";
        case Natures::Naughty:       return "Naughty";
        case Natures::Quiet:         return "Quiet";
        case Natures::Quirky:        return "Quirky";
        case Natures::Rash:          return "Rash";
        case Natures::Relaxed:       return "Relaxed";
        case Natures::Sassy:         return "Sassy";
        case Natures::Serious:       return "Serious";
        case Natures::Timid:         return "Timid";
    
        case Natures::NaturesLength:
        default:                     return "";
    }
}

float Nature::GetModifier(const Stats& Stat) const
{
    switch (Stat)
    {
        case Stats::Attack:         return GetAttackModifier();
        case Stats::Defense:        return GetDefenseModifier();
        case Stats::SpecialAttack:  return GetSpecialAttackModifier();
        case Stats::SpecialDefense: return GetSpecialDefenseModifier();
        case Stats::Speed:          return GetSpeedModifier();

        case Stats::StatsLength:
        default:                    return 1.0f;
    }
}

float Nature::GetAttackModifier() const
{
    return 1.0f;
}

float Nature::GetDefenseModifier() const
{
    return 1.0f;
}

float Nature::GetSpecialAttackModifier() const
{
    return 1.0f;
}

float Nature::GetSpecialDefenseModifier() const
{
    return 1.0f;
}

float Nature::GetSpeedModifier() const
{
    return 1.0f;
}
