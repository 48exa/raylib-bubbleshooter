#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <raylib.h>

typedef char* cstr;

typedef struct
{
  unsigned int width;
  unsigned int height;
  cstr title;
  bool vsync;
  bool drawfps;
  bool fullscreen;
} WindowSettings;

#endif