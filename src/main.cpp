#include <bubbleshooter.h>

int main(void)
{
    uint16_t SCREEN_WIDTH = 1280;
    uint16_t SCREEN_HEIGHT = 720;

    Bubbleshooter *scene = new Bubbleshooter(SCREEN_WIDTH, SCREEN_HEIGHT, "Bubble Shooter");
    scene->toggleDrawFPS();
    scene->toggleVsync();

    while (scene->isActive())
    {
        scene->tick(GetFrameTime());
    }

    return 0;
}
