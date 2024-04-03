#include <mainscene.h>
#include <config.h>
#include <core.h>

int main(int argc, char **argv) {
  Core *core = new Core();

  MainScene *scene = new MainScene(core->settings);

  do {
    core->run(scene);
  } while (scene->isActive());

  return 0;
}
