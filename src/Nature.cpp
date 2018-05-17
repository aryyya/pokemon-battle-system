#include <string>

#include "Nature.h"
#include "Natures.h"
#include "Pokemon.h"
#include "Stats.h"
#include "Utility.h"

// CONSTRUCTORS:

Nature::Nature()
{
    this->Nature_ = static_cast<Natures>(GetRandomInt(0, NaturesLength));
}

Nature::Nature(const Natures& Nature)
{
    this->Nature_ = Nature;
}

// OTHERS:

float Nature::GetModifier(const Stats& Stat) const
{
    switch (Stat)
    {
        case Stats::Attack:         return GetAttackModifier();
        case Stats::Defense:        return GetDefenseModifier();
        case Stats::SpecialAttack:  return GetSpecialAttackModifier();
        case Stats::SpecialDefense: return GetSpecialDefenseModifier();
        case Stats::Speed:          return GetSpeedModifier();
    }
    return 1.0f;
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
