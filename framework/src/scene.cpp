#include <scene.h>
#include <config.h>
#include <additional.h>

Scene::Scene(WindowSettings s) : Entity()
{
  this->settings = s;

  camera = new Camera2D();

  camera->zoom = settings.zoom;

  assert(!GetWindowHandle());
  InitWindow((int)settings.dimensions.x, (int)settings.dimensions.y, settings.title);

  Config::init_settings(settings);

  t = new Timer();
  t->start();
}

Scene::~Scene()
{
  assert(GetWindowHandle());
  CloseWindow();
}

void Scene::tick(float deltaTime)
{
  BeginDrawing();
  BeginMode2D(*camera);

  update(deltaTime);
  draw();

  EndMode2D();
  EndDrawing();
}

void Scene::draw()
{
  ClearBackground(BLACK);
  if (settings.drawfps)
    Additional::DrawFPSPro(10, 10, 30, WHITE, settings.zoom);

  for (Entity *child : this->children())
  {
    DrawTexture(child->texture(), child->position.x, child->position.y, child->color());
  }
}

void Scene::toggleVsync()
{
  settings.vsync = !settings.vsync;
  if (settings.vsync)
    SetWindowState(FLAG_VSYNC_HINT);
  else
  {
    ClearWindowState(FLAG_VSYNC_HINT);
    SetTargetFPS(32767); // Arbitrary FPS limit set to the 16 bit signed integer limit
  }
}