#ifndef SPAWNER_h
#define SPAWNER_h

#include <entity.h>
#include <item.h>
#include <vector>
#include <timer.h>

class Spawner : public Entity {
public:
  Spawner(Vector3 pos, std::vector<Item *> *items, float mult);
  ~Spawner();

  void update(float deltaTime) override;
  void spawnItem();

private:
  float multiplier;
  Timer *t;
  std::vector<Item *> *itemsptr;
};

#endif