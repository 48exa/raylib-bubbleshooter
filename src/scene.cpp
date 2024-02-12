#include <scene.h>

Scene::Scene(int width, int height, std::string title, bool vsync) : Entity()
{
  assert(!GetWindowHandle());
  InitWindow(width, height, title.c_str());

  if (vsync)
    SetTargetFPS(GetMonitorRefreshRate(0));
}

Scene::~Scene()
{
  assert(GetWindowHandle());
  CloseWindow();
}

void Scene::update(float deltaTime)
{
  DrawText("Hello World!", 10, 30, 30, WHITE);
}