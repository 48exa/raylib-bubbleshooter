#ifndef SCENE_H
#define SCENE_H

#include <config.h>
#include <cstring>
#include <entity.h>
#include <timer.h>

/// Represents a scene in the game.
class Scene : public Entity {
public:
  /// Constructs a Scene object with the specified window settings.
  /// @param s The window settings for the scene.
  Scene(WindowSettings s);

  /// Destroys the Scene object.
  ~Scene();

  /// Updates the scene based on the elapsed time.
  /// @param deltaTime The time elapsed since the last update.
  virtual void update(float deltaTime) = 0;

  /// Advances the scene by one frame.
  /// @param deltaTime The time elapsed since the last frame.
  void tick(float deltaTime);

  /// Draws the scene.
  /// @param deltaTime The time elapsed since the last frame.
  void draw(float deltaTime);

  /// Toggles the display of frames per second (FPS) on the screen.
  void toggleDrawFPS() { settings.drawfps = !settings.drawfps; };

  /// Toggles vertical synchronization (VSync) for the scene.
  void toggleVsync();

  /// Checks if the scene is active.
  /// @return True if the scene is active, false otherwise.
  bool isActive() { return !WindowShouldClose(); };

  /// Crashes the scene with the specified error message.
  /// @param msg The error message to display.
  void crash(const char *msg);

  virtual void update_static(float deltaTime) = 0;

  /// The window settings for the scene.
  WindowSettings settings;

  /// The camera used to view the scene.
  Camera2D *camera;

protected:
private:
  /// The timer used to measure time intervals.
  Timer *t;
};

#endif
