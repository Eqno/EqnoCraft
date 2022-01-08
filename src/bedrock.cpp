#include "bedrock.h"

Bedrock::Bedrock(double x, double y, double z): Block(BEDROCKTEX, x, y, z) {}
Bedrock::Bedrock(double x, double y, double z, double r): Block(BEDROCKTEX, x, y, z, r) {}

void addBedrock(double x, double y, double z)
{ block.push_back((Coord *) new Bedrock(x, y, z)); }

void addBedrock(double x, double y, double z, double r)
{ block.push_back((Coord *) new Bedrock(x, y, z, r)); }