#ifndef PLAYER_H
#define PLAYER_H

#include <animatedentity.h>
#include <cmath>
#include <config.h>
#include <timer.h>

// saving a whole 19 bytes with this
constexpr const char *UP = "up";
constexpr const char *DOWN = "down";
constexpr const char *LEFT = "left";
constexpr const char *RIGHT = "right";

class Player : public AnimatedEntity {
public:
  Player(WindowSettings s);
  ~Player();

  void update(float deltaTime) override;
  bool sprinting();
  double *getBalancePtr() { return &balance; };
  void playerMove(bool SHOULD_THE_PLAYER_MOVE_OR_NOT_REALLY_AM_NOT_SURE);

  Rectangle getHitbox();

private:
  void move(float deltaTime);
  void normalizeMovement(float deltaTime);
  void animate(std::string direction);
  void drawShadow();
  void showIdleSprite();

  WindowSettings settings;
  Rectangle source;
  Rectangle dest;
  Vector2 origin;
  Timer *t;

  bool shouldMove;
  double balance;
  float speed;
  int lastDirectionMoved;
};

#endif