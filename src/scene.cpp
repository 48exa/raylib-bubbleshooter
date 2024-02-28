#include <scene.h>

Scene::Scene(uint16_t width, uint16_t height, std::string title) : Entity()
{
  assert(!GetWindowHandle());
  InitWindow(width, height, title.c_str());

  _shouldDrawFPS = false;
  _shouldUseVsync = true;

  if (_shouldUseVsync)
    SetTargetFPS(GetMonitorRefreshRate(0));

  t = new Timer();
  t->start();
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
  for (Entity *child : this->children())
  {
    DrawTexture(child->texture(), child->position.x, child->position.y, child->color());
  }
}

void Scene::toggleVsync()
{
  this->_shouldUseVsync = !this->_shouldUseVsync;
  if (_shouldUseVsync)
    SetWindowState(FLAG_VSYNC_HINT);
  else
    SetTargetFPS(32767); // Arbitrary FPS limit set to the 16 bit signed integer limit
}