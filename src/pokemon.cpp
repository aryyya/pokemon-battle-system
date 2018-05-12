#include "Pokemon.h"
#include "Type.h"
#include <string>
#include <iostream>

Pokemon::Pokemon(const std::string Name, const Type Type_, const int Health, const int Attack,
    const int Defence, const int SpecialAttack, const int SpecialDefence, const int Speed)
{
    this->Name           = Name;
    this->Type_          = Type_;
    this->Health         = Health;
    this->Attack         = Attack;
    this->Defence        = Defence;
    this->SpecialAttack  = SpecialAttack;
    this->SpecialDefence = SpecialDefence;
    this->Speed          = Speed;
}

std::string Pokemon::ToString() const
{
    return
        "{ "
        "Name: "           + Name                           + ", "
        "Type: "           + Type_.ToString()               + ", "
        "Health: "         + std::to_string(Health)         + ", "
        "Attack: "         + std::to_string(Attack)         + ", "
        "Defence: "        + std::to_string(Defence)        + ", "
        "SpecialAttack: "  + std::to_string(SpecialAttack)  + ", "
        "SpecialDefence: " + std::to_string(SpecialDefence) + ", "
        "Speed: "          + std::to_string(Speed)          + ""
        " }";
}

std::string Pokemon::GetName() const
{
    return Name;
}

Type Pokemon::GetType() const
{
    return Type_;
}

int Pokemon::GetAttack() const
{
    return Attack;
}

int Pokemon::GetSpeed() const
{
    return Speed;
}

int Pokemon::GetHealth() const
{
    return Health;
}

void Pokemon::TakeDamage(const int Damage)
{
    std::cout << Name << " took " << Damage << " damage\n";
    Health -= Damage;
}

bool Pokemon::IsAlive() const
{
    return Health > 0;
}

std::string Pokemon::GetStatus()
{
    return Name + ": " + std::to_string(Health) + " Health (" + (IsAlive() ? "conscious" : "unconscious") + ")";
}
