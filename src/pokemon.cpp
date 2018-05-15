#include <string>
#include <iostream>
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
            TypesString += ", ";
        }
    }
    return TypesString;
}

int Pokemon::GetHealth() const
{
    return Health;
}

int Pokemon::GetAttack() const
{
    return Attack;
}

int Pokemon::GetDefense() const {
    return Defense;
}

int Pokemon::GetSpecialAttack() const
{
    return SpecialAttack;
}

int Pokemon::GetSpecialDefense() const
{
    return SpecialDefense;
}

int Pokemon::GetSpeed() const
{
    return Speed;
}

// OTHERS:

std::string Pokemon::ToString() const
{
    return
        "{ "
        "Name: "           + Name                           + ", "
        "Types: "          + GetTypesString()               + ", "
        "Health: "         + std::to_string(Health)         + ", "
        "Attack: "         + std::to_string(Attack)         + ", "
        "Defense: "        + std::to_string(Defense)        + ", "
        "SpecialAttack: "  + std::to_string(SpecialAttack)  + ", "
        "SpecialDefense: " + std::to_string(SpecialDefense) + ", "
        "Speed: "          + std::to_string(Speed)          + ""
        " }";
}

std::string Pokemon::GetStatus()
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

std::vector<Type> Pokemon::GetTypesFromStrings(const std::vector<std::string>& Strings)
{
    std::vector<Type> Types;

    for (const std::string& String : Strings)
    {
        Types.push_back(Type(String));
    }

    return Types;
}
