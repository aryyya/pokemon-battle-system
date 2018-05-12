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
        Grass
    };

    Type();
    Type(const Types Type);

    std::string ToString() const;

    float GetModifier(const Type& Defender) const;

private:
    Types Type_;
};
