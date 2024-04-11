#include <config.h>
#include <core.h>
#include <mainscene.h>

int main(int argc, char *argv[]) {
  Core *core = new Core();

  core->settings.title = "Tygoon";
  core->settings.size = {1280, 720};
  core->settings.color = {76, 63, 47, 255};
  core->settings.vsync = false;
  core->settings.drawfps = true;
  core->settings.fullscreen = false;
  core->settings.resizable = true;
  core->settings.zoom = 5.0f;

  MainScene *scene = new MainScene(core->settings);

  do {
    core->run(scene);
  } while (scene->isActive());

  return 0;
}
