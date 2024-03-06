#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <raylib.h>

typedef char *cstr;

/// @brief Screen dimensions
/// @param uint width
/// @param uint height
typedef struct Dimensions
{
  unsigned int width;
  unsigned int height;
} Dimensions;

/// @brief Settings for the window
/// @param Dimensions dimensions
/// @param cstr title
/// @param bool vsync
/// @param bool drawfps
/// @param bool fullscreen
/// @param bool resizable
/// @param bool MSAA
/// @param bool windowDecorated
typedef struct WindowSettings
{
  Dimensions dimensions;
  cstr title;
  bool vsync;
  bool drawfps;
  bool fullscreen;
  bool resizable;
  bool MSAA;
  bool windowDecorated;

} WindowSettings;

#endif