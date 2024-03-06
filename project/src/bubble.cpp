#include <bubble.h>

Image Bubble::texturebuf = LoadImage("../assets/bubble.png");

Bubble::Bubble(float posx, float posy, Color color) : Entity()
{
  this->position = {posx, posy};
  this->addTextureFromImage(texturebuf);
  this->setTextureColor(color);
  SetTextureFilter(this->texture(), TEXTURE_FILTER_ANISOTROPIC_16X);

  this->speed = 1000;
}

Bubble::~Bubble()
{
}

void Bubble::update(float deltaTime)
{
}

void Bubble::move(float angle, float deltaTime)
{
  Vector2 dir = {cos(angle), sin(angle)};
  Vector2 move = {dir.x * speed * deltaTime, dir.y * speed * deltaTime};

  this->position.x -= move.x;
  this->position.y -= move.y;
}

void Bubble::clamp(Vector2 limits)
{
  if (this->position.x < -12)
    this->angleToMove = PI - this->angleToMove;

  if (this->position.x > limits.x - this->texture().width)
    this->angleToMove = PI - this->angleToMove;
}

bool Bubble::outOfBounds(int upperBound)
{
  return (this->position.y < -16 - this->texture().height || this->position.y > upperBound);
}