/**
 * @file scene.h
 *
 * @brief Header file of the scene class
 *
 * This file is part of RLFWB, a RayLib Framework for Bubbleshooter
 *
 * - Copyright 2024 Douwe westerdijk <westerdijk@protonmail.com>
 *
 */

#ifndef SCENE_H
#define SCENE_H

#include <entity.h>
#include <timer.h>
#include <config.h>

class Scene : public Entity
{
public:
  /// @brief Constructor of a Scene
  /// @param width Width of the screen in pixels.
  /// @param height Height of the screen in pixels.
  /// @param title Title of the screen
  Scene(WindowSettings s);
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
  void toggleDrawFPS() { settings.drawfps = !settings.drawfps; };
  /// @brief Toggle the use of vsync
  /// @return void
  void toggleVsync();
  /// @brief Wether the scene is active or not
  /// @return Wether the scene is active or not
  bool isActive() { return !WindowShouldClose(); };
  Vector2 getMouse()
  {
    return Vector2{(float)GetMouseX(), (float)GetMouseY()};
  };
  WindowSettings settings;

protected:
private:
  Camera2D *camera;
  Timer *t;
  /// @brief Wether or not the scene should draw FPS
};

#endif
