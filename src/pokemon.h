#pragma once

#include <string>
#include <vector>

#include "Nature.h"
#include "Type.h"

#include <nlohmann/json.hpp>

enum Stats
{
    Attack,
    Defense,
    SpecialAttack,
    SpecialDefense,
    Speed,
    StatsLength
};

class Pokemon
{
    // PROPERTIES:

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
    float Individual;
    float Effort;
    Nature Nature;

    // CONSTRUCTORS:

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

private:
    void Initialize(
        const std::string Name,
        const std::vector<Type> Types,
        const int Health,
        const int Attack,
        const int Defense,
        const int SpecialAttack,
        const int SpecialDefense,
        const int Speed);

    // GETTERS AND SETTERS:
    
public:
    std::string GetName() const;

    const std::vector<Type>& GetTypes() const;

    const std::string GetTypesString() const;

    int GetHealth() const;

    int GetLevel() const;

    void SetLevel(const int Level);

    int GetAttack() const;

    int GetDefense() const;

    int GetSpecialAttack() const;

    int GetSpecialDefense() const;

    int GetSpeed() const;

    // OTHERS:

public:
    std::string ToString() const;

    std::string GetStatus() const;

    bool IsAlive() const;

    void TakeDamage(const int Damage);

private:
    std::vector<Type> GetTypesFromStrings(const std::vector<std::string>& Strings) const;

    int GetLevelAdjustedHealthStat(const int HealthBaseStat) const;

    int GetLevelAdjustedStat(const Stats& Stat, const int BaseStat) const;
};
