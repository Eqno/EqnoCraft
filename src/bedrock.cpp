#include "bedrock.h"

Bedrock::Bedrock(double x, double y, double z): Block(BEDROCKTEX, x, y, z) {}
Bedrock::Bedrock(double x, double y, double z, double r): Block(BEDROCKTEX, x, y, z, r) {}

std::vector<Coord *> bedrock;

void addBedrock(double x, double y, double z)
{ bedrock.push_back((Coord *) new Bedrock(x, y, z)); }

void addBedrock(double x, double y, double z, double r)
{ bedrock.push_back((Coord *) new Bedrock(x, y, z, r)); }

void renderBedrock()
{ for (const auto &i: bedrock) i->show(); }