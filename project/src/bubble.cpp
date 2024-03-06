#include <bubble.h>

Image Bubble::texturebuf = LoadImage("../assets/bubble.png");

Bubble::Bubble(float posx, float posy, Color color) : Entity()
{
  this->position = {posx, posy};
  std::cout << "Bubble Placed at " << posx << ", " << posy << std::endl;
  this->addTextureFromImage(texturebuf);
  this->setTextureColor(color);
}

Bubble::~Bubble()
{
}

void Bubble::update(float deltaTime)
{
}