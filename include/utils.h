#ifndef UTILS_H
#define UTILS_H

#include <cmath>
const double pi = 4*atan(1), EPS = 1e-4;

#define ull unsigned long long
ull getHash(int, int);
void anaHash(ull, int &, int &);
inline double toRad(double deg)
{ return deg * pi / 180; }

#endif