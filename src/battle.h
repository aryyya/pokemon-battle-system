#pragma once

#include "Pokemon.h"

class Battle
{
public:
    Battle(Pokemon& Pokemon1, Pokemon& Pokemon2);

    void Round();

    void Attack(Pokemon& Attacker, Pokemon& Defender);

private:
    Pokemon& Pokemon1;
    Pokemon& Pokemon2;
};
