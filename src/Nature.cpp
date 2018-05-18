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
    return NaturesNaturesToStringMap.at(Nature_);
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
    return FindModifier(NaturesThatRaiseAttack, NaturesThatLowerAttack);
}

float Nature::GetDefenseModifier() const
{
    return FindModifier(NaturesThatRaiseDefense, NaturesThatLowerDefense);
}

float Nature::GetSpecialAttackModifier() const
{
    return FindModifier(NaturesThatRaiseSpecialAttack, NaturesThatLowerSpecialAttack);
}

float Nature::GetSpecialDefenseModifier() const
{
    return FindModifier(NaturesThatRaiseSpecialDefense, NaturesThatLowerSpecialDefense);
}

float Nature::GetSpeedModifier() const
{
    return FindModifier(NaturesThatRaiseSpeed, NaturesThatLowerSpeed);
}

float Nature::FindModifier(const std::vector<Natures>& NaturesThatRaiseStat, const std::vector<Natures>& NaturesThatLowerStat) const
{
    if (Exists(Nature_, NaturesThatRaiseStat))
    {
        return 1.1f;
    }
    else if (Exists(Nature_, NaturesThatLowerStat))
    {
        return 0.9f;
    }
    else
    {
        return 1.0f;
    }
}
