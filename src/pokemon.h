#pragma once

#include <string>
#include <vector>

#include "Type.h"

#include <nlohmann/json.hpp>

class Pokemon
{
public:
    Pokemon(
        const std::string Name,
        const std::vector<Type> Types,
        const int Health,
        const int Attack,
        const int Defense,
        const int SpecialAttack,
        const int SpecialDefense,
        const int Speed);

    Pokemon(const nlohmann::json& Config);
        
    std::string ToString() const;

    std::string GetName() const;

    const std::vector<Type>& GetTypes() const;

    const std::string GetTypesString() const;

    int GetAttack() const;

    int GetSpeed() const;

    int GetHealth() const;

    void TakeDamage(const int Damage);

    bool IsAlive() const;

    std::string GetStatus();

private:
    std::string Name;
    std::vector<Type> Types;
    int Health;
    int Level;
    int Attack;
    int Defense;
    int SpecialAttack;
    int SpecialDefense;
    int Speed;

    std::vector<Type> GetTypesFromStrings(const std::vector<std::string>& Strings);
};
