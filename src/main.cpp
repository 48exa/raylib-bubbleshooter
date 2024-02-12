#include <raylib.h>
#include <scene.h>

int main(void)
{

    Scene *scene = new Scene(1280, 720, "Bubble Shooter");

    while (scene->scene_active())
    {
        BeginDrawing();

        ClearBackground(BLACK);
        DrawText("Hello World!", 10, 30, 16, WHITE);
        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
