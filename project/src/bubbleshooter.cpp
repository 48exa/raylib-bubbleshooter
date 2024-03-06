#include <bubbleshooter.h>
#include <config.h>
#include <additional.h>

Bubbleshooter::Bubbleshooter(WindowSettings settings) : Scene(settings)
{
  t = new Timer();
  t->start();

  bubble = new Bubble((settings.dimensions.x / 2) / settings.zoom, (settings.dimensions.y / settings.zoom) - 64);
  this->addChild(bubble);

  for (int y = 0; y < (settings.dimensions.y / 2) / settings.zoom; y += 65)
  {
    for (int x = 8; x < (settings.dimensions.x - 32) / settings.zoom; x += 65)
    {
      if (y % 130 == 0)
        this->addChild(new Bubble(x + 32, y, Additional::genRandomColor()));
      else
        this->addChild(new Bubble(x, y, Additional::genRandomColor()));
    }
  }
}

Bubbleshooter::~Bubbleshooter()
{
  for (Entity *child : this->children())
  {
    this->removeChild(child);
  }
}

void Bubbleshooter::update(float deltaTime)
{
  if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
  {
    Vector2 m = {getMouse().x / settings.zoom, getMouse().y / settings.zoom};
    Vector2 player = {bubble->position.x + bubble->texture().width / 2, bubble->position.y + bubble->texture().height / 2};

    float deltaX = player.x - m.x;
    float deltaY = player.y - m.y;

    float angleInRadians = atan2(deltaY, deltaX);

    // Convert the angle to degrees
    float angleInDegrees = angleInRadians * 180 / PI;

    // Adjust the angle to be between 0 and 360 degrees
    if (angleInDegrees < 0)
    {
      angleInDegrees += 360;
    }

    DrawLineEx(m, player, 2, WHITE);
  }

  if (IsKeyPressed(KEY_Q))
  {
    this->toggleVsync();
  }
}
