#include <scene.h>

Scene::Scene(uint16_t width, uint16_t height, std::string title)
{
  InitWindow(width, height, title.c_str());
}

Scene::~Scene()
{
}

void Scene::update(float deltaTime)
{
}

bool Scene::scene_active() const
{
  return WindowShouldClose();
}