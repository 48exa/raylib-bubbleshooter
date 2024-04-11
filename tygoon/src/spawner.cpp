#include <spawner.h>

Spawner::Spawner(Vector3 pos, std::vector<Item *> *items, float mult = 1.0f) : Entity() {
  t = new Timer();
  t->start();
  position = pos;
  addTexture("assets/spawner.png");
  itemsptr = items;

  multiplier = mult;
}

Spawner::~Spawner() {
}

void Spawner::update(float deltaTime) {
  DrawTexture(texture(), position.x, position.y, WHITE);

  if (t->getSeconds() > GetRandomValue(1, 50) / 5.0f) {
    spawnItem();
    t->restart();
  }
}

void Spawner::spawnItem() {
  itemsptr->push_back(new Item({position.x, position.y}, GetRandomValue(1, 10) * multiplier));
}