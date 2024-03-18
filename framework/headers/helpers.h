#ifndef HELPERS_H
#define HELPERS_H

#include <charconv>
#include <iostream>
#include <raylib.h>
#include <string>

/// @class Helpers
/// @brief A utility class that provides helper functions for various tasks.
class Helpers {
public:
  /// @brief Generates a random color.
  /// @return A randomly generated color.
  static Color genRandomColor() {
    switch (rand() % 5) {
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
