#ifndef BUTTON_H
#define BUTTON_H

#include <entity.h>

class Button : public Entity {
public:
  Button(Rectangle btn, Vector2 pos);
  ~Button();

  virtual void update(float deltaTime);

private:
  Rectangle size;
};

#endif