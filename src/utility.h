#pragma once

#include <vector>
#include <unordered_map>

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

template <typename TKey, typename TValue>
std::unordered_map<TValue, TKey> GetFlipped(const std::unordered_map<TKey, TValue>& Map)
{
    std::unordered_map<TValue, TKey> FlippedMap;
    for (auto Iterator = Map.begin(); Iterator != Map.end(); Iterator++)
    {
        FlippedMap[Iterator->second] = Iterator->first;
    }
    return FlippedMap;
}
