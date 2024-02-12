#ifndef BUBBLESHOOTER_H
#define BUBBLESHOOTER_H

#include <scene.h>

class Bubbleshooter : public Scene
{
public:
  Bubbleshooter(uint16_t width, uint16_t height, std::string title);
  ~Bubbleshooter();

  virtual void update(float deltaTime);

private:
};

#endif