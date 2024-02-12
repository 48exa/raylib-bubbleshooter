#ifndef SCENE_H
#define SCENE_H

#include <entity.h>

class Scene : public Entity
{
public:
  /// @brief Constructor of a Scene
  /// @param width Width of the screen in pixels.
  /// @param height Height of the screen in pixels.
  /// @param title Title of the screen
  Scene(uint16_t width, uint16_t height, std::string title);
  /// @brief Deconstructor of a scene
  ~Scene();

  /// @brief Update the scene. This function is PURE VIRTUAL. You MUST implement it when extending from Scene.
  /// @param deltaTime Time elapsed since last frame draw.
  /// @return void
  virtual void update(float deltaTime) = 0;
  /// @brief Core of the Entity, runs every frame until the user closes app
  /// @param deltaTime Time elapsed since last frame draw.
  /// @return void
  void tick(float deltaTime);
  /// @brief Clear the background and possibly draw the FPS
  /// @return void
  void draw();
  /// @brief Toggle the drawing of the FPS
  /// @return void
  void toggleDrawFPS() { this->_shouldDrawFPS = !this->_shouldDrawFPS; };
  /// @brief Toggle the use of vsync
  /// @return void
  void toggleVsync();
  /// @brief Wether the scene is active or not
  /// @return Wether the scene is active or not
  bool isActive() { return !WindowShouldClose(); };

private:
  /// @brief Wether or not the scene should draw FPS
  bool _shouldDrawFPS;
  /// @brief Wether or not the scene should use vsync
  bool _shouldUseVsync;
};

#endif