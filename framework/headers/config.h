#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <raylib.h>

// Bubble related constants
#define BUBBLE_SPAWN_Y_OFFSET 64
#define BUBBLE_SIZE           32
#define Y_INCREMENT           65
#define X_INCREMENT           65

// Screen related constants
#define GAME_SCREEN_OFFSET_X  -12
#define GAME_SCREEN_OFFSET_Y  -16
#define GAME_BORDER_THICKNESS 10
#define CAMERA_OFFSET         25
#define Y_THRESHOLD           600
#define X_THRESHOLD           800

// Offset related constants
#define X_EXTRA_OFFSET 32
#define Y_EXTRA_OFFSET 130
#define MOUSE_OFFSET   48
#define Y_OFFSET       32
#define X_OFFSET       38

// Aimer related constants
#define AIMER_LENGTH 250
#define MOUSE_OFFSET 48

#define BUTTON_COLOR \
  { 153, 153, 204, 255 }
#define GAME_SCREEN_COLOR \
  { 198, 198, 255, 255 }
#define GAME_SCREEN_BORDER_COLOR \
  { 230, 230, 255, 255 }

constexpr Vector2 SIZE = {1200, 700};
constexpr const char *TITLE = "Bubbleshooter";
constexpr Color COLOR = {192, 192, 255, 255};
constexpr bool VSYNC = true;
constexpr bool DRAWFPS = true;
constexpr bool FULLSCREEN = false;
constexpr bool RESIZABLE = false;
constexpr bool MSAA = true;
constexpr bool WINDOW_DECORATED = true;
constexpr float ZOOM = 0.5f;
constexpr Vector2 SIZE_SCALED = {SIZE.x / ZOOM, SIZE.y / ZOOM};
constexpr Vector2 GAME_SIZE = {816 / ZOOM, 616 / ZOOM};

/// @brief Struct representing the settings for a window.
typedef struct WindowSettings {
  Vector2 size = SIZE;                      /**< The size of the window. */
  Vector2 size_scaled = SIZE_SCALED;        /**< The scaled size of the window. */
  Vector2 game_size = GAME_SIZE;            /**< The size of the game. */
  const char *title = TITLE;                /**< The title of the window. */
  Color color = COLOR;                      /**< The color of the window. */
  bool vsync = VSYNC;                       /**< Whether to enable vertical sync. */
  bool drawfps = DRAWFPS;                   /**< Whether to draw the frames per second. */
  bool fullscreen = FULLSCREEN;             /**< Whether to enable fullscreen mode. */
  bool resizable = RESIZABLE;               /**< Whether the window is resizable. */
  bool MSAA = MSAA;                         /**< Whether to enable multisample anti-aliasing. */
  bool window_decorated = WINDOW_DECORATED; /**< Whether the window has decorations. */
  float zoom = ZOOM;                        /**< The zoom level of the window. */
} WindowSettings;

/// @class Config
/// @brief The Config class provides a static method to initialize window
/// settings for the application.
///
/// The Config class is used to configure various window settings such as vsync,
/// resizable window, MSAA, window decoration, and fullscreen mode. The
/// init_settings method takes a WindowSettings object as a parameter and
/// applies the specified settings to the window.
class Config {
public:
  Config() = delete;

  /// @brief Initializes the window settings based on the provided
  /// WindowSettings object.
  /// @param settings The WindowSettings object containing the desired window
  /// settings.
  static void init_settings(WindowSettings settings) {
    if (settings.vsync)
      SetWindowState(FLAG_VSYNC_HINT);

    if (settings.resizable)
      SetWindowState(FLAG_WINDOW_RESIZABLE);

    if (settings.MSAA) {
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