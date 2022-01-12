#include "utils.h"

ull getHash(int x, int y)
{
    return ((unsigned long long) (unsigned) x) << 32 | (unsigned long long) (unsigned) y;
}

void anaHash(ull hash, int &x, int &y)
{
    x = (int) (hash >> 32);
    y = (int) (hash << 32 >> 32);
}