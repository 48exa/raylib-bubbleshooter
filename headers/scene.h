#ifndef SCENE_H
#define SCENE_H

#include <raylib.h>
#include <iostream>

class Scene
{
public:
  Scene(uint16_t width, uint16_t height, std::string title);
  ~Scene() noexcept;
  virtual void update(float deltaTime);

  bool scene_active() const;

private:
};

#endif