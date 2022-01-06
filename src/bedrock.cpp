#include "bedrock.h"

Bedrock::Bedrock(): Block(BEDROCKTEX) {}
Bedrock::Bedrock(double x, double y, double z): Block(BEDROCKTEX, x, y, z) {}
Bedrock::Bedrock(double x, double y, double z, double r): Block(BEDROCKTEX, x, y, z, r) {}

std::vector<Block> bedrock;

void addBedrock()
{
    bedrock.push_back(Bedrock());
}
void addBedrock(double x, double y, double z)
{
    bedrock.push_back(Bedrock(x, y, z));
}
void addBedrock(double x, double y, double z, double r)
{
    bedrock.push_back(Bedrock(x, y, z, r));
}
void renderBedrock()
{
    for (const auto &i: bedrock) i.show();
}