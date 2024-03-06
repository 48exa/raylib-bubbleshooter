#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <raylib.h>

typedef const char *cstr;

/// @brief Settings for the window
/// @param Vector2 dimensions
/// @param cstr title
/// @param bool vsync
/// @param bool drawfps
/// @param bool fullscreen
/// @param bool resizable
/// @param bool MSAA
/// @param bool windowDecorated
/// @param float zoom
typedef struct WindowSettings
{
  Vector2 dimensions;
  cstr title;
  bool vsync;
  bool drawfps;
  bool fullscreen;
  bool resizable;
  bool MSAA;
  bool windowDecorated;
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
      SetWindowState(FLAG_MSAA_4X_HINT);

    if (!settings.windowDecorated)
      SetWindowState(FLAG_WINDOW_UNDECORATED);

    if (settings.fullscreen)
      SetWindowState(FLAG_FULLSCREEN_MODE);
  }
};

#endif