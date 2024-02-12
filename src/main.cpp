#include "raylib.h"
#include "scene.h"
#include "../framework/timer.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");

    // Scene *scene = new Scene();
    // Timer *timer = new Timer();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        // scene->update(GetFrameTime());
        // timer->update(GetFrameTime());

        // if (timer->time() == 1)
        // {
        //     std::cout << "FPS:\t" << GetFPS() << "fps\tTime per frame:\t" << GetFPS() / 1000 << "ms" << std::endl;
        //     timer->reset();
        // }

        DrawFPS(100, 100);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
