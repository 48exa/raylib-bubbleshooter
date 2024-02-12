#include <bubbleshooter.h>

Bubbleshooter::Bubbleshooter(uint16_t width, uint16_t height, std::string title)
    : Scene(width, height, title)
{
}

Bubbleshooter::~Bubbleshooter()
{
}

void Bubbleshooter::update(float deltaTime)
{
  DrawText("Bubble shooting", 10, 30, 40, WHITE);
}