#include <spawner.h>

Spawner::Spawner(Vector3 pos, std::vector<Item *> *items, double cost, float mult = 1.0f) : Entity() {
  t = new Timer();
  position = pos;
  this->cost = cost;
  position.y += 10;
  addTexture("assets/spawnerplate.png");
  itemsptr = items;

  multiplier = mult;
}

Spawner::~Spawner() {
}

void Spawner::update(float deltaTime) {
  if (active && !newTexture) {
    removeTexture();
    addTexture("assets/spawner.png");
    newTexture = true;
  }

  DrawTexture(texture(), position.x, position.y, WHITE);

  if (!active) {
    const char *formattedCost = CashCollector::formatCash(cost);
    DrawText(formattedCost, position.x, position.y + 32, 10, WHITE);
  }

  if (t->getSeconds() > 2.0f && active) {
    spawnItem();
    t->restart();
  }
}

void Spawner::spawnItem() {
  itemsptr->push_back(new Item({position.x, position.y}, GetRandomValue(1, 10) * multiplier));
}

void Spawner::setActive() {
  active = true;
}