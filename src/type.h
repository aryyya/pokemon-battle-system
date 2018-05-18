#pragma once

#include <string>

#include "Types.h"

class Type
{
    // PROPERTIES:

private:
    Types Type_;

    // CONSTRUCTORS:

public:
    Type();

    Type(const Types& Type);

    Type(const std::string& Type);

    // OTHERS:

public:
    std::string ToString() const;

    float GetModifier(const Type& Defender) const;

private:
    Types ToType(const std::string Type) const;
};
