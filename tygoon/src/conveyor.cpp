#include <conveyor.h>

Conveyor::Conveyor(Rectangle conveyor) : Entity() {
  this->conveyor = {conveyor.x, conveyor.y, conveyor.width, conveyor.height};
  itemCollector = {conveyor.x + conveyor.width, conveyor.y, conveyor.height, conveyor.height};
  playerHB = {0};
}

Conveyor::~Conveyor() {
}

void Conveyor::update(float deltaTime) {
  DrawRectangle(conveyor.x, conveyor.y, conveyor.width, conveyor.height, DARKGRAY);
  DrawRectangleLines(conveyor.x, conveyor.y, conveyor.width, conveyor.height, GRAY);

  DrawRectangle(itemCollector.x, itemCollector.y, itemCollector.width, itemCollector.height, GREEN);
  DrawRectangleLines(itemCollector.x, itemCollector.y, itemCollector.width, itemCollector.height, DARKGREEN);

  if (CheckCollisionRecs(playerHB, conveyor)) {
    (*player)->position.x += 100 * deltaTime;
  }
}

void Conveyor::sendHitbox(Player **p) {
  playerHB = (*p)->getHitbox();
  player = p;
}