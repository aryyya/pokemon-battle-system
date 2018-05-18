#include <string>

#include "Type.h"
#include "Types.h"

// CONSTRUCTORS:

Type::Type()
{
    this->Type_ = Types::Normal;
}

Type::Type(const Types& Type)
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
    return TypesTranslations.at(Type_);
}

float Type::GetModifier(const Type& Defender) const
{
    if (Type_ == Types::Fire)
    {
        if (Defender.Type_ == Types::Fire)
        {
            return 0.5f;
        }
    }
        if (Type_ == Types::Fire)
    {
        if (Defender.Type_ == Types::Fire)
        {
            return 0.5f;
        }
        if (Defender.Type_ == Types::Water)
        {
            return 0.5f;
        }
        if (Defender.Type_ == Types::Grass)
        {
            return 2.0f;
        }
    }
    if (Type_ == Types::Water)
    {
        if (Defender.Type_ == Types::Fire)
        {
            return 2.0f;
        }
        if (Defender.Type_ == Types::Water)
        {
            return 0.5f;
        }
        if (Defender.Type_ == Types::Grass)
        {
            return 0.5f;
        }
    }
    if (Type_ == Types::Grass)
    {
        if (Defender.Type_ == Types::Fire)
        {
            return 0.5f;
        }
        if (Defender.Type_ == Types::Water)
        {
            return 2.0f;
        }
        if (Defender.Type_ == Types::Grass)
        {
            return 0.5f;
        }
    }
    return 1.0f;
}

Types Type::ToType(const std::string Type) const
{
    if (Type == "Normal") return Types::Normal;
    if (Type == "Fire")   return Types::Fire;
    if (Type == "Water")  return Types::Water;
    if (Type == "Grass")  return Types::Grass;
    if (Type == "Flying") return Types::Flying;
    return Types::Normal;
}
