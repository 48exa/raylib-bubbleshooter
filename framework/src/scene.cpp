#include <scene.h>
#include <config.h>
#include <helpers.h>

Scene::Scene(WindowSettings s) : Entity()
{
  this->settings = s;

  camera = new Camera2D();

  camera->zoom = settings.zoom;

  Config::init_settings(settings);

  assert(!GetWindowHandle());
  InitWindow((int)settings.size.x, (int)settings.size.y, settings.title);

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
  ClearBackground(settings.color);
  if (settings.drawfps)
  {
    char title[255];
    strcpy(title, "Bubbleshooter | FPS: ");
    strcat(title, Helpers::int2char(GetFPS()));
    SetWindowTitle(title);
  }

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