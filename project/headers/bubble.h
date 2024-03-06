#ifndef BUBBLE_H
#define BUBBLE_H

#include <entity.h>

class Bubble : public Entity
{
public:
  Bubble(float posx, float posy, Color color = WHITE);
  ~Bubble();
  virtual void update(float deltaTime);

private:
  static Image texturebuf;
};

#endif