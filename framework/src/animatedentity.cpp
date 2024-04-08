#include <animatedentity.h>

AnimatedEntity::AnimatedEntity() : Entity() {
  spriteCount = 1;
  spriteSize = 16;
  spriteTime = 1.0f;
  spriteIndex = 0;
  spriteStartIndex = 0;
}

AnimatedEntity::~AnimatedEntity() {
}
