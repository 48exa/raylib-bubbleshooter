#ifndef ITEM_H
#define ITEM_H

#include <entity.h>
#include <cashcollector.h>

class Item : public Entity {
public:
  Item(Vector2 position, double value);
  ~Item();

  void update(float deltaTime) override;
  double getValue() { return value; };

  Rectangle getHitbox() { return item; };
  Rectangle item;

private:
  void colorItem();
  Color col;
  double value;
};

#endif