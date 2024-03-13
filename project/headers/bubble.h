#ifndef BUBBLE_H
#define BUBBLE_H

#include <entity.h>
#include <math.h>
#include <config.h>

/// Bubble class represents a bubble entity in the game.
class Bubble : public Entity
{
public:
  /// Constructor for Bubble class.
  /// @param posx The x-coordinate of the bubble's position.
  /// @param posy The y-coordinate of the bubble's position.
  /// @param vis Whether the bubble is visible or not.
  /// @param color The color of the bubble (default is WHITE).
  Bubble(float posx, float posy, bool vis, Color color = WHITE);

  /// Destructor for Bubble class.
  ~Bubble();

  /// Updates the bubble's state.
  /// @param deltaTime The time elapsed since the last update.
  virtual void update(float deltaTime);

  /// Indicates whether the bubble should move or not.
  bool shouldMove;

  /// The destination of the bubble.
  Vector2 destination;

  /// The original position of the bubble.
  Vector2 origin;

  /// The direction of the bubble's movement.
  Vector2 direction;

  /// Indicates whether the bubble is visible or not.
  bool visible;

  /// Bounces the bubble off a surface.
  void bounce();

protected:
  /// The speed of the bubble.
  int speed;

private:
  friend class Bubbleshooter;
};

#endif