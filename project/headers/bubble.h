#ifndef BUBBLE_H
#define BUBBLE_H

#include <entity.h>
#include <math.h>
#include <config.h>

class Bubble : public Entity
{
public:
  Bubble(float posx, float posy, bool vis, Color color = WHITE);
  ~Bubble();
  virtual void update(float deltaTime);

  bool shouldMove;
  Vector2 destination;
  Vector2 origin;
  Vector2 direction;
  bool visible;
  void bounce();

protected:
  int speed;

private:
  friend class Bubbleshooter;
  WindowSettings settings;
};

#endif