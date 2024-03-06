#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <raylib.h>
#include <charconv>
#include <string>

class Helpers
{
public:
  static char *int2char(int i)
  {
    size_t length = std::to_string(i).length();
    char *result = new char[length + 1];
    std::to_chars(result, result + length + 1, i);
    result[length] = '\0';

    return result;
  };

  static void DrawFPSPro(int posx, int posy, int fontsize, Color color, float zoom = 1.0f)
  {
    DrawText(int2char(GetFPS()), posx, posy, fontsize / zoom, color);
  };

  static Color genRandomColor()
  {
    switch (rand() % 5)
    {
    case 0:
      return GREEN;
    case 1:
      return BLUE;
    case 2:
      return YELLOW;
    case 3:
      return PURPLE;
    case 4:
      return RED;
    default:
      return GREEN;
    }
  }
};

#endif
