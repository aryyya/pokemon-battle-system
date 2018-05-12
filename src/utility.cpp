#include <cstdlib>

#include "Utility.h"

int GetRandomInt(const int min, const int max)
{
    return std::rand() % (max - min + 1) + min;
}
