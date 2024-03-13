#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <raylib.h>
#include <charconv>
#include <string>

/// @class Helpers
/// @brief A utility class that provides helper functions for various tasks.
class Helpers
{
public:
  /// @brief Converts an integer to a character array.
  /// @param i The integer to be converted.
  /// @return A dynamically allocated character array representing the integer.
  static char *int2char(int i)
  {
    size_t length = std::to_string(i).length();
    char *result = new char[length + 1];
    std::to_chars(result, result + length + 1, i);
    result[length] = '\0';

    return result;
  };

  /// @brief Generates a random color.
  /// @return A randomly generated color.
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
