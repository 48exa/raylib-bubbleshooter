#include <scene.h>

Scene::Scene(uint16_t width, uint16_t height, std::string title) : Entity()
{
  assert(!GetWindowHandle());
  InitWindow(width, height, title.c_str());

  _shouldDrawFPS = false;
  _shouldUseVsync = true;

  if (_shouldUseVsync)
    SetTargetFPS(GetMonitorRefreshRate(0));
}

Scene::~Scene()
{
  assert(GetWindowHandle());
  CloseWindow();
}

void Scene::update(float deltaTime)
{
}

void Scene::tick(float deltaTime)
{
  BeginDrawing();
  update(deltaTime);
  draw();
  EndDrawing();
}

void Scene::draw()
{
  ClearBackground(BLACK);
  if (_shouldDrawFPS)
    DrawFPS(10, 10);
}

void Scene::toggleVsync()
{
  this->_shouldUseVsync = !this->_shouldUseVsync;
  if (_shouldUseVsync)
    SetTargetFPS(GetMonitorRefreshRate(0));
  else
    SetTargetFPS(32768); // Arbitrary FPS limit set to the 16 bit signed integer limit
}