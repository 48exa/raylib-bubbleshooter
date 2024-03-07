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

#define GAME_SCREEN_COLOR {198, 198, 255, 255}
#define GAME_SCREEN_BORDER_COLOR {230, 230, 255, 255}
#define GAME_SCREEN_OFFSET_X -12
#define GAME_SCREEN_OFFSET_Y -16
#define GAME_BORDER_THICKNESS 10

typedef const char *cstr;


/// @brief Settings for the window
/// @param Vector2 size
/// @param cstr title
/// @param bool vsync
/// @param bool drawfps
/// @param bool fullscreen
/// @param bool resizable
/// @param bool MSAA
/// @param bool window_decorated
/// @param float zoom
/// @param Vector2 game_size
typedef struct WindowSettings
{
  Vector2 size;
  Vector2 size_scaled;
  Vector2 game_size;
  cstr title;
  Color color;
  bool vsync;
  bool drawfps;
  bool fullscreen;
  bool resizable;
  bool MSAA;
  bool window_decorated;
  float zoom;
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