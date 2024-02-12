#include <scene.h>

int main(void)
{
    int SCREEN_WIDTH = 1280;
    int SCREEN_HEIGHT = 720;

    Scene *scene = new Scene(SCREEN_WIDTH, SCREEN_HEIGHT, "Bubble Shooter");
    scene->toggleDrawFPS();
    scene->toggleVsync();

    while (scene->isActive())
    {
        scene->tick(GetFrameTime());
    }

    return 0;
}
