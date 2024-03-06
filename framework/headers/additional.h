#ifndef ADDITIONAL_H
#define ADDITIONAL_H

#include <iostream>
#include <raylib.h>
#include <charconv>
#include <string>

class Additional
{
public:
  static void DrawFPSPro(int posx, int posy, int fontsize, Color color, float zoom = 1.0f)
  {
    unsigned int fps = GetFPS();                         // Get current frames per second
    size_t length = std::to_string(fps).length();        // Calculate the number of digits in the FPS value
    char *fps_char = new char[length + 1];               // Allocate space for the FPS string plus null terminator
    std::to_chars(fps_char, fps_char + length + 1, fps); // Convert the FPS value to a character array
    fps_char[length] = '\0';                             // Explicitly set the null terminator

    DrawText(fps_char, posx, posy, fontsize / zoom, color); // Draw the FPS on the screen

    delete[] fps_char; // Free the dynamically allocated memory to avoid memory leak
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
