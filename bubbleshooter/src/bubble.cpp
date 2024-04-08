#include <bubble.h>

Bubble::Bubble(float posx, float posy, bool vis, Color color) : Entity() {
  this->visible = false;
  this->position = {0};
  this->shouldMove = false;
  this->setTextureColor(WHITE);
  this->destination = {0};
  this->origin = {0};
  this->direction = {0};
  this->speed = 0;

  this->position = {posx, posy};
  this->speed = 1000;
  this->shouldMove = false;
  this->visible = vis;
  this->setTextureColor(color);
}

Bubble::~Bubble() {
}

void Bubble::update(float deltaTime) {
  if (visible) {
    DrawCircle((int)position.x, (int)position.y, BUBBLE_SIZE, color());
  } else {
    DrawCircleLines((int)position.x, (int)position.y, BUBBLE_SIZE, {255, 255, 255, 255});
  }

  if (shouldMove) {
    this->position.x += this->direction.x * speed * deltaTime;
    this->position.y += this->direction.y * speed * deltaTime;
  }
}

void Bubble::bounce() {
  this->direction.x *= -1;
}

void Bubble::setNeighbors(const std::vector<Bubble *> *bubbles) {
  /*
    NW NE
   E  *  W
    SW SE
  */

  for (size_t n = 0; n < (*bubbles).size(); n++) {
    (*bubbles)[n]->neighbors["NW"] = (*bubbles)[n - 24];
    (*bubbles)[n]->neighbors["NE"] = (*bubbles)[n - 23];
    (*bubbles)[n]->neighbors["W"] = (*bubbles)[n + 1];
    (*bubbles)[n]->neighbors["SE"] = (*bubbles)[n + 25];
    (*bubbles)[n]->neighbors["SW"] = (*bubbles)[n + 24];
    (*bubbles)[n]->neighbors["E"] = (*bubbles)[n - 1];
  }
}