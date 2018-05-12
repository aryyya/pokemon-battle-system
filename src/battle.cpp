#include "Battle.h"
#include "Pokemon.h"
#include "Type.h"
#include "Utility.h"
#include <iostream>

Battle::Battle(Pokemon& Pokemon1, Pokemon& Pokemon2)
    : Pokemon1(Pokemon1), Pokemon2(Pokemon2)
{
}

void Battle::Round()
{
    if (Pokemon1.GetSpeed() > Pokemon2.GetSpeed())
    {
        std::cout << Pokemon1.GetName() << " is faster than " << Pokemon2.GetName() << "\n";
        Attack(Pokemon1, Pokemon2);
        Attack(Pokemon2, Pokemon1);
    }
    else if (Pokemon1.GetSpeed() < Pokemon2.GetSpeed())
    {
        std::cout << Pokemon2.GetName() << " is faster than " << Pokemon1.GetName() << "\n";
        Attack(Pokemon2, Pokemon1);
        Attack(Pokemon1, Pokemon2);
    }
    else
    {
        std::cout << Pokemon1.GetName() << " has the same speed as " << Pokemon2.GetName() << "\n";
        if (GetRandomInt(0, 1) == 0)
        {
            Attack(Pokemon1, Pokemon2);
            Attack(Pokemon2, Pokemon1);
        }
        else
        {
            Attack(Pokemon2, Pokemon1);
            Attack(Pokemon1, Pokemon2);
        }
    }

    std::cout << Pokemon1.GetStatus() << "\n";
    std::cout << Pokemon2.GetStatus() << "\n";
}

void Battle::Attack(Pokemon& Attacker, Pokemon& Defender)
{    
    std::cout << Attacker.GetName() << " attacks " << Defender.GetName() << "\n";

    const float AttackModifier = Attacker.GetType().GetModifier(Defender.GetType());

    std::cout << Attacker.GetName() << " has a " << AttackModifier << "x attack modifier against " << Defender.GetName() << "\n";

    const float AttackDamage = AttackModifier * Attacker.GetAttack();

    std::cout << Attacker.GetName() << " does " << AttackDamage << "\n";

    Defender.TakeDamage(AttackDamage);
}
