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

  void move(float angle, float deltaTime);
  void clamp(Vector2 limits);

  bool shouldMove;
  float angleToMove;
  bool outOfBounds(int upperBound);

protected:
  int speed;

private:
  static Image texturebuf;

  friend class Bubbleshooter;
};

#endif