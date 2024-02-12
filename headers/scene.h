#ifndef SCENE_H
#define SCENE_H

#include <entity.h>

class Scene : public Entity
{
public:
  Scene(int width, int height, std::string title, bool vsync);
  ~Scene() noexcept;

private:
  virtual void update(float deltaTime);
};

#endif