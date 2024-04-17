#ifndef SPAWNER_h
#define SPAWNER_h

#include <entity.h>
#include <item.h>
#include <timer.h>
#include <vector>
#include <cashcollector.h>

class Spawner : public Entity {
public:
  Spawner(Vector3 pos, std::vector<Item *> *items, double cost, float mult);
  ~Spawner();

  void update(float deltaTime) override;
  void spawnItem();
  void setActive();
  bool isActive() { return active; };
  double cost;

private:
  float multiplier;

  Timer *t;

  // ptr to vector in mainscene
  std::vector<Item *> *itemsptr;

  bool active = false;
  bool newTexture = false;
};

#endif