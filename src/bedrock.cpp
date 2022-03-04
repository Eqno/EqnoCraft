#include <bedrock.h>
#include <init.h>
#include <world.h>

Bedrock::Bedrock(double x, double y, double z)
    : Block(texture->bedrock, x, y, z) {}
Bedrock::Bedrock(double x, double y, double z, double r)
    : Block(texture->bedrock, x, y, z, r) {}

void addBedrock(double x, double y, double z) { addBlock<Bedrock>(x, y, z); }
void addBedrock(double x, double y, double z, double r) {
  addBlock<Bedrock>(x, y, z, r);
}

BedrockLayer::BedrockLayer() {
  for (int i = -World::INIT_WIDTH; i <= World::INIT_WIDTH; i++)
    for (int j = -World::INIT_LENGTH; j <= World::INIT_LENGTH; j++)
      addBedrock(i, this->INIT_DEPTH, j);
}