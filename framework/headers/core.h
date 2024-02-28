#ifndef CORE_H
#define CORE_H

#include <raylib.h>
#include <scene.h>

class Core
{
public:
  Core();
  ~Core();

  void run(Scene *scene);

protected:
  float deltaTime;

private:
};

#endif