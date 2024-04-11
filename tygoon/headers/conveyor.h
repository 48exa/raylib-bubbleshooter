#ifndef CONVEYOR_H
#define CONVEYOR_H

#include <entity.h>
#include <player.h>

class Conveyor : public Entity {
public:
  Conveyor(Rectangle conveyor);
  ~Conveyor();

  void update(float deltaTime) override;
  void update_static(float deltaTime);
  void sendHitbox(Player **p);
  Rectangle itemCollector;

private:
  Rectangle conveyor;
  Rectangle playerHB;
  Player **player;
};

#endif