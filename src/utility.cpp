#include "Utility.h"
#include <cstdlib>

int GetRandomInt(const int min, const int max)
{
    return std::rand() % (max - min + 1) + min;
}
