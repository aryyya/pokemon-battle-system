#pragma once

#include <string>

#include "Natures.h"
#include "Pokemon.h"
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
    float GetModifier(const Stats& Stat) const;

private:
    float GetAttackModifier() const;

    float GetDefenseModifier() const;

    float GetSpecialAttackModifier() const;

    float GetSpecialDefenseModifier() const;

    float GetSpeedModifier() const;
};
