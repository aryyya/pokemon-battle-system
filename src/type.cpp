#include <string>

#include "Type.h"

// CONSTRUCTORS:

Type::Type()
{
    this->Type_ = Normal;
}

Type::Type(Types Type)
{
    this->Type_ = Type;
}

Type::Type(const std::string& Type)
{
    this->Type_ = ToType(Type);
}

// OTHERS:

std::string Type::ToString() const
{
    switch (Type_)
    {
        case Types::Normal: return "Normal";
        case Types::Fire:   return "Fire";
        case Types::Water:  return "Water";
        case Types::Grass:  return "Grass";
        case Types::Flying: return "Flying";
    }
}

float Type::GetModifier(const Type& Defender) const
{
    if (Type_ == Type::Fire)
    {
        if (Defender.Type_ == Type::Fire)
        {
            return 0.5f;
        }
    }
        if (Type_ == Type::Fire)
    {
        if (Defender.Type_ == Type::Fire)
        {
            return 0.5f;
        }
        if (Defender.Type_ == Type::Water)
        {
            return 0.5f;
        }
        if (Defender.Type_ == Type::Grass)
        {
            return 2.0f;
        }
    }
    if (Type_ == Type::Water)
    {
        if (Defender.Type_ == Type::Fire)
        {
            return 2.0f;
        }
        if (Defender.Type_ == Type::Water)
        {
            return 0.5f;
        }
        if (Defender.Type_ == Type::Grass)
        {
            return 0.5f;
        }
    }
    if (Type_ == Type::Grass)
    {
        if (Defender.Type_ == Type::Fire)
        {
            return 0.5f;
        }
        if (Defender.Type_ == Type::Water)
        {
            return 2.0f;
        }
        if (Defender.Type_ == Type::Grass)
        {
            return 0.5f;
        }
    }
    return 1.0f;
}

Type::Types Type::ToType(const std::string Type) const
{
    if (Type == "Normal") return Types::Normal;
    if (Type == "Fire")   return Types::Fire;
    if (Type == "Water")  return Types::Water;
    if (Type == "Grass")  return Types::Grass;
    if (Type == "Flying") return Types::Flying;
    return Types::Normal;
}
