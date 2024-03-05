#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <tuple>
#include <raylib.h>

typedef struct
{
  unsigned int width;
  unsigned int height;
  char *title;
  bool vsync;
  bool drawfps;
  bool fullscreen;
} WindowSettings;

#endif