#include <bubbleshooter.h>
#include <config.h>
#include <helpers.h>

Bubbleshooter::Bubbleshooter(WindowSettings s) : Scene(s)
{
  t = new Timer();
  t->start();

  bubbleSpawnLocation = {settings.game_size.x / 2 - 32, settings.game_size.y - 96};

  camera->offset = {25, 25};

  bubble = nullptr;

  for (int y = 0; y < 600 / settings.zoom / 2; y += 65)
  {
    for (int x = 8; x < 800 / settings.zoom - 64; x += 65)
    {
      if (y % 130 == 0)
        this->addChild(new Bubble(x + 32, y, Helpers::genRandomColor()));
      else
        this->addChild(new Bubble(x, y, Helpers::genRandomColor()));
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
  // TODO: jesus clean this up
  DrawRectangle(-12, -16, settings.game_size.x, settings.game_size.y, {198, 198, 255, 255});
  DrawRectangleLinesEx({-12, -16, settings.game_size.x, settings.game_size.y}, 10, {230, 230, 255, 255});
  DrawCircleLines(settings.game_size.x / 2, settings.game_size.y - 64, 32, WHITE);

  // TODO: Clamp aimAngle so user can't shoot downwards
  Vector2 m = {GetMouseX() / settings.zoom, GetMouseY() / settings.zoom};
  Vector2 shooterPos = {bubbleSpawnLocation.x + 32, bubbleSpawnLocation.y + 32};
  float angle = atan2(shooterPos.y - m.y, shooterPos.x - m.x);

  // DrawLineV(lineStart, line, RED);

  if (IsKeyPressed(KEY_Q))
  {
    this->toggleVsync();
  }

  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
  {
    if (bubble != nullptr)
      return;

    bubble = new Bubble(bubbleSpawnLocation.x, bubbleSpawnLocation.y, Helpers::genRandomColor());
    this->addChild(bubble);

    Vector2 m = {GetMouseX() / settings.zoom, GetMouseY() / settings.zoom};
    Vector2 shooterPos = {bubbleSpawnLocation.x + 32, bubbleSpawnLocation.y + 32};

    bubble->angleToMove = angle;

    bubble->shouldMove = !bubble->shouldMove;
  }

  if (bubble == nullptr)
    return;

  if (!bubble->shouldMove)
    return;

  bubble->move(bubble->angleToMove, deltaTime);
  bubble->clamp(settings.game_size);

  if (bubble->outOfBounds(settings.game_size.y) || IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
  {
    bubble->shouldMove = false;
    this->removeChild(bubble);
    delete bubble;

    this->bubble = nullptr;
  }
}
