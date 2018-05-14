#include <string>
#include <iostream>
#include <vector>

#include "Pokemon.h"
#include "Type.h"

#include <nlohmann/json.hpp>

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
    this->Name           = Name;
    this->Types          = Types;
    this->Health         = Health;
    this->Level          = 1;
    this->Attack         = Attack;
    this->Defense        = Defense;
    this->SpecialAttack  = SpecialAttack;
    this->SpecialDefense = SpecialDefense;
    this->Speed          = Speed;
}

Pokemon::Pokemon(const nlohmann::json& Config)
{
    this->Name           = Config["Name"];
    this->Types          = GetTypesFromStrings(Config["Types"]);
    this->Health         = Config["Health Points"];
    this->Level          = 1;
    this->Attack         = Config["Attack"];
    this->Defense        = Config["Defense"];
    this->SpecialDefense = Config["Special Defense"];
    this->SpecialAttack  = Config["Special Attack"];
    this->Speed          = Config["Speed"];
}

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

std::vector<Type> Pokemon::GetTypesFromStrings(const std::vector<std::string>& Strings)
{
    std::vector<Type> Types;

    for (const std::string& String : Strings)
    {
        Types.push_back(Type(String));
    }

    return Types;
}

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
