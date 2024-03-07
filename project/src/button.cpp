#include <button.h>
#include <config.h>

Button::Button(Rectangle btn, Vector2 pos) : Entity()
{
  this->position = {pos.x, pos.y};
  this->size = {btn.x, btn.y, btn.width, btn.height};
}

Button::~Button()
{
}

void Button::update(float deltaTime)
{
  DrawRectangle(position.x, position.y, size.x, size.y, BUTTON_COLOR);
}