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

#ifndef TIMER_H
#define TIMER_H

#include <raylib.h>
#include <assert.h>

class Timer
{
public:
  Timer();
  ~Timer();

  /// @brief Start the Timer, also functions as reset
  void start();
  /// @brief Stop the Timer
  void stop();
  /// @brief The number of seconds passed since the Timer started
  /// @return double time in seconds
  double getSeconds();
  void restart() { start(); };

private:
  /// @brief When we started
  double _startTime;
  /// @brief When we paused
  double _pausedTicks;
  /// @brief Started or not
  bool _started;
  ///< @brief Paused or not
  bool _paused;

private:
};

#endif