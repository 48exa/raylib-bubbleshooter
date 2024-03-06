#include <scene.h>
#include <config.h>

Scene::Scene(WindowSettings s) : Entity()
{
  this->settings = s;
  assert(!GetWindowHandle());
  InitWindow(settings.dimensions.width, settings.dimensions.height, settings.title);

  if (settings.vsync)
    SetWindowState(FLAG_VSYNC_HINT);

  if (settings.resizable)
    SetWindowState(FLAG_WINDOW_RESIZABLE);

  if (settings.MSAA)
    SetWindowState(FLAG_MSAA_4X_HINT);

  if (!settings.windowDecorated)
    SetWindowState(FLAG_WINDOW_UNDECORATED);

  if (settings.fullscreen)
    SetWindowState(FLAG_FULLSCREEN_MODE);

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
  update(deltaTime);
  draw();
  EndDrawing();
}

void Scene::draw()
{
  ClearBackground(BLACK);
  if (settings.drawfps)
  {
    DrawFPS(10, 10);
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