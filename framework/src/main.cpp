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

    core->settings.width = 1250;
    core->settings.height = 1000;
    core->settings.title = "Bubbleshooter";
    core->settings.vsync = true;
    core->settings.drawfps = true;
    core->settings.fullscreen = true;

    Bubbleshooter *scene = new Bubbleshooter(core->settings);

    while (scene->isActive())
    {
        core->run(scene);
    }

    return 0;
}
