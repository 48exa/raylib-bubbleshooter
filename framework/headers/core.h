#ifndef CORE_H
#define CORE_H

#include <raylib.h>
#include <scene.h>
#include <config.h>

/// The Core class represents the core functionality of the application.
/// The Core class is responsible for managing the main loop of the application and
/// handling the rendering and updating of scenes.
class Core
{
public:
  /// Constructs a Core object.
  Core();

  /// Destructs the Core object.
  ~Core();

  /// Runs the application with the specified scene.
  /// This method starts the main loop of the application and continuously updates
  /// and renders the specified scene until the application is closed.
  /// @param scene A pointer to the Scene object to run.
  void run(Scene *scene);

  WindowSettings settings; ///< The settings for the application window.

protected:
  float deltaTime; ///< The time elapsed since the last frame.

private:
};

#endif