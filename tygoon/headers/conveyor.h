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
  void sendPlayer(Player **p);

  Rectangle itemCollector;
  Rectangle conveyor;

private:
  void getHitbox();
  Rectangle playerHB;
  Player **playerptr;
};

#endif