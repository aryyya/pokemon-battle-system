#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "Pokemon.h"
#include "Type.h"

#include <nlohmann/json.hpp>

// CONSTRUCTORS:

Pokemon::Pokemon(
    const std::string Name,
    const std::vector<Type> Types,
    const int Health,
    const int Attack,
    const int Defense,
    const int SpecialAttack,
    const int SpecialDefense,
    const int Speed)
{
    Initialize(
        Name,
        Types,
        Health,
        Attack,
        Defense,
        SpecialAttack,
        SpecialDefense,
        Speed);
}

Pokemon::Pokemon(const nlohmann::json& Config)
{
    Initialize(
        Config["Name"],
        GetTypesFromStrings(Config["Types"]),
        Config["Health Points"],
        Config["Attack"],
        Config["Defense"],
        Config["Special Attack"],
        Config["Special Defense"],
        Config["Speed"]);
}

void Pokemon::Initialize(
    const std::string Name,
    const std::vector<Type> Types,
    const int Health,
    const int Attack,
    const int Defense,
    const int SpecialAttack,
    const int SpecialDefense,
    const int Speed)
{
    this->Name = Name;
    this->Types = Types;
    this->Health = Health;
    this->Attack = Attack;
    this->Defense = Defense;
    this->SpecialAttack = SpecialAttack;
    this->SpecialDefense = SpecialDefense;
    this->Speed = Speed;

    this->Individual = 0.0f;
    this->Effort = 0.0f;

    this->Level = 1;
}

// GETTERS AND SETTERS:

std::string Pokemon::GetName() const
{
    return Name;
}

const std::vector<Type>& Pokemon::GetTypes() const
{
    return Types;
}

const std::string Pokemon::GetTypesString() const
{
    std::string TypesString;
    for (unsigned int i = 0; i < Types.size(); i++)
    {
        TypesString += Types[i].ToString();
        if (i < Types.size() - 1)
        {
            TypesString += "/";
        }
    }
    return TypesString;
}

int Pokemon::GetHealth() const
{
    return GetLevelAdjustedHealthStat(Health);
}

int Pokemon::GetLevel() const
{
    return Level;
}

void Pokemon::SetLevel(const int Level)
{
    this->Level = Level;
}

int Pokemon::GetAttack() const
{
    return GetLevelAdjustedStat(Stats::Attack, Attack);
}

int Pokemon::GetDefense() const {
    return GetLevelAdjustedStat(Stats::Defense, Defense);
}

int Pokemon::GetSpecialAttack() const
{
    return GetLevelAdjustedStat(Stats::SpecialAttack, SpecialAttack);
}

int Pokemon::GetSpecialDefense() const
{
    return GetLevelAdjustedStat(Stats::SpecialDefense, SpecialDefense);
}

int Pokemon::GetSpeed() const
{
    return GetLevelAdjustedStat(Stats::Speed, Speed);
}

// OTHERS:

std::string Pokemon::ToString() const
{
    return
        "{\n"
        "  Name: "           + Name                                + ",\n"
        "  Types: "          + GetTypesString()                    + ",\n"
        "  Health: "         + std::to_string(GetHealth())         + ",\n"
        "  Attack: "         + std::to_string(GetAttack())         + ",\n"
        "  Defense: "        + std::to_string(GetDefense())        + ",\n"
        "  SpecialAttack: "  + std::to_string(GetSpecialAttack())  + ",\n"
        "  SpecialDefense: " + std::to_string(GetSpecialDefense()) + ",\n"
        "  Speed: "          + std::to_string(GetSpeed())          + "\n"
        "}";
}

std::string Pokemon::GetStatus() const
{
    return Name + ": " + std::to_string(Health) + " Health (" + (IsAlive() ? "conscious" : "unconscious") + ")";
}

bool Pokemon::IsAlive() const
{
    return Health > 0;
}

void Pokemon::TakeDamage(const int Damage)
{
    std::cout << Name << " took " << Damage << " damage\n";
    Health -= Damage;
}

std::vector<Type> Pokemon::GetTypesFromStrings(const std::vector<std::string>& Strings) const
{
    std::vector<Type> Types;
    for (const std::string& String : Strings)
    {
        Types.push_back(Type(String));
    }
    return Types;
}

int Pokemon::GetLevelAdjustedHealthStat(const int HealthBaseStat) const
{
    return (2 * HealthBaseStat + Individual + Effort) * Level / 100 + Level + 10;
}

int Pokemon::GetLevelAdjustedStat(const Stats& Stat, const int BaseStat) const
{
    const float NatureModifier = Nature.GetModifier(Stat);

    return floor((2 * BaseStat + Individual + Effort) * Level / 100 + 5) * NatureModifier;
}
