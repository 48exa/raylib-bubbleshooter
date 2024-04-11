#include <item.h>

Item::Item(Vector2 position, double value) : Entity() {
  this->value = value;
  item = {position.x, position.y, 10, 10};
  col = WHITE;
}

Item::~Item() {
}

void Item::update(float deltaTime) {
  colorItem();
  DrawRectangle(item.x, item.y, item.width, item.height, col);
}

void Item::colorItem() {
  col = BLACK;
  if (value > 0.0f) {
    col = {255, 255, 255, 255};
  }
  if (value > 500.0f) {
    col = {100, 255, 100, 255};
  }
  if (value > 1000.0f) {
    col = {100, 100, 255, 255};
  }
  if (value > 5000.0f) {
    col = {255, 0, 0, 255};
  }
  if (value > 10000.0f) {
    col = {0, 255, 0, 255};
  }
  if (value > 50000.0f) {
    col = {0, 0, 255, 255};
  }
}