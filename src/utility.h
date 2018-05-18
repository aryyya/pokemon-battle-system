#pragma once

#include <vector>

int GetRandomInt(const int min, const int max);

template<typename T>
bool Exists(const T& Value, const std::vector<T>& Collection)
{
    for (const T& Element : Collection)
    {
        if (Value == Element)
        {
            return true;
        }
    }
    return false;
}
