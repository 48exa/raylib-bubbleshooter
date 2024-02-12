#include "raylib.h"

int main()
{
    InitWindow(1280, 720, "Window title");

    while (!WindowShouldClose())
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
