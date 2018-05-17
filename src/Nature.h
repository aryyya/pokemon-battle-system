#pragma once

#include <string>

#include "Pokemon.h"

class Pokemon;

enum Natures
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

class Nature
{
    // PROPERTIES:

private:
    Natures Nature_;

    // CONSTRUCTORS:

public:
    Nature();

    Nature(const Natures Nature);

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
