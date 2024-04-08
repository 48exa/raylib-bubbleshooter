#ifndef PLAYER_H
#define PLAYER_H

#include <animatedentity.h>
#include <cmath>
#include <config.h>
#include <timer.h>

constexpr const char *UP = "up";
constexpr const char *DOWN = "down";
constexpr const char *LEFT = "left";
constexpr const char *RIGHT = "right";

class Player : public AnimatedEntity {
public:
  Player(WindowSettings s);
  ~Player();

  void update(float deltaTime) override;

private:
  void move(float deltaTime);
  void normalizeMovement(float deltaTime);
  void animate(std::string direction);
  void drawShadow();
  void showIdleSprite();

  WindowSettings settings;
  Timer *t;

  float speed = 100.0f;
  int lastDirectionMoved;
};

#endif