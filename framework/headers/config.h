#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <raylib.h>

#define BUBBLE_SIZE 32
#define BUBBLE_SPAWN_Y_OFFSET 64
#define CAMERA_OFFSET 25
#define Y_INCREMENT 65
#define X_INCREMENT 65
#define Y_THRESHOLD 600
#define X_THRESHOLD 800
#define Y_OFFSET 32
#define X_OFFSET 38
#define X_EXTRA_OFFSET 32
#define Y_EXTRA_OFFSET 130

#define AIMER_LENGTH 250

#define GAME_SCREEN_COLOR {198, 198, 255, 255}
#define GAME_SCREEN_BORDER_COLOR {230, 230, 255, 255}
#define GAME_SCREEN_OFFSET_X -12
#define GAME_SCREEN_OFFSET_Y -16
#define GAME_BORDER_THICKNESS 10

#define BUTTON_COLOR {205, 198, 255, 255}

typedef const char *cstr;

constexpr Vector2 SIZE = {1200, 700};
constexpr cstr TITLE = "Bubbleshooter";
constexpr Color COLOR = {192, 192, 255, 255};
constexpr bool VSYNC = true;
constexpr bool DRAWFPS = true;
constexpr bool FULLSCREEN = false;
constexpr bool RESIZABLE = false;
constexpr bool MSAA = true;
constexpr bool WINDOW_DECORATED = true;
constexpr float ZOOM = 0.5f;
constexpr Vector2 SIZE_SCALED = {SIZE.x / ZOOM, SIZE.y / ZOOM};
constexpr Vector2 GAME_SIZE = {816 / ZOOM, 616 / ZOOM};

typedef struct WindowSettings
{
  Vector2 size = SIZE;
  Vector2 size_scaled = SIZE_SCALED;
  Vector2 game_size = GAME_SIZE;
  cstr title = TITLE;
  Color color = COLOR;
  bool vsync = VSYNC;
  bool drawfps = DRAWFPS;
  bool fullscreen = FULLSCREEN;
  bool resizable = RESIZABLE;
  bool MSAA = MSAA;
  bool window_decorated = WINDOW_DECORATED;
  float zoom = ZOOM;
} WindowSettings;

class Config
{
public:
  Config() = delete;

  static void init_settings(WindowSettings settings)
  {
    if (settings.vsync)
      SetWindowState(FLAG_VSYNC_HINT);

    if (settings.resizable)
      SetWindowState(FLAG_WINDOW_RESIZABLE);

    if (settings.MSAA)
    {
      SetConfigFlags(FLAG_MSAA_4X_HINT);
      SetWindowState(FLAG_MSAA_4X_HINT);
    }

    if (!settings.window_decorated)
      SetWindowState(FLAG_WINDOW_UNDECORATED);

    if (settings.fullscreen)
      SetWindowState(FLAG_FULLSCREEN_MODE);
  }
};

#endif