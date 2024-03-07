#ifndef BUBBLE_H
#define BUBBLE_H

#include <entity.h>
#include <math.h>

class Bubble : public Entity
{
public:
  Bubble(float posx, float posy, Color color = WHITE);
  ~Bubble();
  virtual void update(float deltaTime);

  bool shouldMove;
  Vector2 destination;
  Vector2 origin;
  Vector2 direction;

protected:
  int speed;

private:
  friend class Bubbleshooter;
};

#endif