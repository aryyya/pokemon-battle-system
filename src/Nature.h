#pragma once

#include <string>

#include "Natures.h"
#include "Stats.h"

class Nature
{
    // PROPERTIES:

private:
    Natures Nature_;

    // CONSTRUCTORS:

public:
    Nature();

    Nature(const Natures& Nature);

    // OTHERS:

public:
    std::string ToString() const;

    float GetModifier(const Stats& Stat) const;

private:
    float GetAttackModifier() const;

    float GetDefenseModifier() const;

    float GetSpecialAttackModifier() const;

    float GetSpecialDefenseModifier() const;

    float GetSpeedModifier() const;

    float FindModifier(const std::vector<Natures>& NaturesThatRaiseStat, const std::vector<Natures>& NaturesThatLowerStat) const;
};
