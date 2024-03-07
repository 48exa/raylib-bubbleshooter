#include <bubble.h>

Bubble::Bubble(float posx, float posy, Color color) : Entity()
{
  this->position = {posx, posy};
  this->setTextureColor(color);
  this->speed = 1000;
  this->shouldMove = false;
}

Bubble::~Bubble()
{
}

void Bubble::update(float deltaTime)
{
  DrawCircle(position.x, position.y, 32, color());

  if (shouldMove)
  {
    this->position.x += this->direction.x * 1000 * deltaTime;
    this->position.y += this->direction.y * 1000 * deltaTime;
  }
}