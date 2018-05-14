#pragma once

#include <string>

class Type
{
public:
    enum Types
    {
        Normal,
        Fire,
        Water,
        Grass,
        Flying
    };

    Type();
    Type(const Types Type);
    Type(const std::string& Type);

    std::string ToString() const;

    float GetModifier(const Type& Defender) const;

private:
    Types Type_;

    Types ToType(const std::string Type) const;
};
