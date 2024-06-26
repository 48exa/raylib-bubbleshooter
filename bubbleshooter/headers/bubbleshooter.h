/**
 * @file timer.h
 *
 * @brief Header file of the Timer class
 *
 * This file is part of RLFWB, a RayLib Framework for Bubbleshooter
 *
 * - Copyright 2024 Douwe westerdijk <westerdijk@protonmail.com>
 *
 */

#ifndef BUBBLESHOOTER_H
#define BUBBLESHOOTER_H

#include <bubble.h>
#include <cmath>
#include <config.h>
#include <scene.h>
#include <timer.h>

class Bubbleshooter : public Scene {
public:
  Bubbleshooter(WindowSettings settings);
  void initlevel();
  ~Bubbleshooter();

  virtual void update(float deltaTime);
  virtual void update_static(float deltaTime) override;

  void deleteBubble();
  bool outOfBounds();
  void shootBubble(bool &retFlag);
  void drawGameLayout(float deltaTime);

  Vector2 GetMouseAccurate();

private:
  Vector2 bubbleSpawnLocation;
  Vector2 mousePosition;
  Vector2 lineDirection;
  Vector2 lineEnd;
  Bubble *bubble;
  std::vector<Bubble *> bubbles;

  Timer *t;
};

#endif