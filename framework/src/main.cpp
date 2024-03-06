/**
 * Copyright 2024 Douwe Westerdijk <westerdijk@protonmail.com>
 *
 * @brief Entry point of Bubbleshooter
 *
 * @file main.cpp
 *
 * @mainpage Bubbleshooter is a classic singleplayer game to play when there is absolutely nothing else left to do.
 *
 * @section Goal
 *
 * Pop the colored bubbles by shooting similarly colored bubbles at them.
 * If you get more than **four** bubbles of the same color next to each other,
 * you pop the bubbles! Now just do it until the entire screen is cleared to win!
 *
 * @section Controls
 *
 * Use your mouse, the A and D key or your arrow keys to aim
 * (I haven't implemented any of these yet maybe you use mind control in the final version idk)
 * and press space or enter to shoot your bubble!
 */

#include <bubbleshooter.h>
#include <core.h>
#include <config.h>

int main(void)
{
    Core *core = new Core();

    // core->settings = {1280, 720, "bubbleshooter", true, true};

    core->settings.size = {1200, 700};
    core->settings.title = "Bubbleshooter";
    core->settings.color = {192, 192, 255, 255};
    core->settings.vsync = true;
    core->settings.drawfps = true;
    core->settings.fullscreen = false;
    core->settings.resizable = false;
    core->settings.MSAA = true;
    core->settings.window_decorated = true;
    core->settings.zoom = 0.5f;
    core->settings.size_scaled = {core->settings.size.x / core->settings.zoom, core->settings.size.y / core->settings.zoom};
    core->settings.game_size = {816 / core->settings.zoom, 616 / core->settings.zoom};

    Bubbleshooter *scene = new Bubbleshooter(core->settings);

    while (scene->isActive())
    {
        core->run(scene);
    }

    return 0;
}
