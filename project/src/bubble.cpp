#include <bubble.h>

Bubble::Bubble(float posx, float posy, bool vis, Color color) : Entity()
{
  this->position = {posx, posy};
  this->setTextureColor(color);
  this->speed = 1000;
  this->shouldMove = false;
  this->visible = vis;
  settings = {0};
}

Bubble::~Bubble()
{
}

void Bubble::update(float deltaTime)
{
  if (visible)
    DrawCircle(position.x, position.y, BUBBLE_SIZE, color());

  if (shouldMove)
  {
    this->position.x += this->direction.x * 1000 * deltaTime;
    this->position.y += this->direction.y * 1000 * deltaTime;
  }
}

void Bubble::bounce()
{
  this->direction.x *= -1;
}