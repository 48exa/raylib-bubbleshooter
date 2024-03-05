#ifndef CORE_H
#define CORE_H

#include <raylib.h>
#include <scene.h>
#include <config.h>

class Core
{
public:
  Core();
  ~Core();

  void run(Scene *scene);

  WindowSettings settings;

protected:
  float deltaTime;

private:
};

#endif