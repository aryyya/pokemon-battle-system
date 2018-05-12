#pragma once

#include <string>
#include <vector>

#include "Type.h"

class Pokemon
{
public:
    Pokemon(const std::string Name, const std::vector<Type> Types, const int Health, const int Attack,
        const int Defence, const int SpecialAttack, const int SpecialDefence, const int Speed);
        
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
    int Attack;
    int Defence;
    int SpecialAttack;
    int SpecialDefence;
    int Speed;
};
