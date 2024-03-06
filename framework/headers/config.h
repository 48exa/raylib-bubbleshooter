#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <raylib.h>

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