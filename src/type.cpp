#include "Type.h"
#include <string>

Type::Type()
{
    this->Type_ = Normal;
}

Type::Type(Types Type)
{
    this->Type_ = Type;
}

std::string Type::ToString() const
{
    switch (Type_)
    {
        case Types::Normal: return "Normal";
        case Types::Fire:   return "Fire";
        case Types::Water:  return "Water";
        case Types::Grass:  return "Grass";
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
