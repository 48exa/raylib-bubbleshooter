#ifndef ENTITYANIMATION_H
#define ENTITYANIMATION_H

#include <entity.h>

class AnimatedEntity : public Entity {
public:
  AnimatedEntity();
  ~AnimatedEntity();

  void update(float deltaTime) = 0;

  float spriteTime;
  float spriteSize;
  int spriteCount;
  int spriteIndex;
  int spriteStartIndex;

  float spriteTimer = spriteTime;
};

#endif