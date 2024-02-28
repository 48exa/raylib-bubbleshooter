#ifndef BUBBLE_H
#define BUBBLE_H

#include <entity.h>

class Bubble : public Entity
{
public:
  Bubble();
  ~Bubble();
  virtual void update(float deltaTime);

private:
};

#endif