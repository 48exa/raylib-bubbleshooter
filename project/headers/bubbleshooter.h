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

#include <scene.h>
#include <timer.h>
#include <bubble.h>
#include <config.h>
#include <cmath>

class Bubbleshooter : public Scene
{
public:
  Bubbleshooter(WindowSettings settings);
  ~Bubbleshooter();

  virtual void update(float deltaTime);

private:
  Vector2 bubbleSpawnLocation;
  Bubble *bubble;
  std::vector<Bubble *> bubbles;
  Timer *t;
};

#endif