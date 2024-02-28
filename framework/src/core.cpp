#include <core.h>

Core::Core()
{
}

Core::~Core()
{
}

void Core::run(Scene *scene)
{
  deltaTime = GetFrameTime();
  scene->tick(deltaTime);
}
