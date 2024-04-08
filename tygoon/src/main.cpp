#include <config.h>
#include <core.h>
#include <mainscene.h>

int main(int argc, char *argv[]) {
  Core *core = new Core();

  core->settings.title = "Tygoon";
  core->settings.size = {1280, 720};
  core->settings.color = {25, 25, 25, 255};
  core->settings.vsync = true;
  core->settings.drawfps = true;
  core->settings.fullscreen = false;
  core->settings.resizable = true;

  MainScene *scene = new MainScene(core->settings);

  do {
    core->run(scene);
  } while (scene->isActive());

  return 0;
}
