#include <bubbleshooter.h>
#include <config.h>
#include <helpers.h>

Bubbleshooter::Bubbleshooter(WindowSettings s) : Scene(s)
{
  t = new Timer();
  t->start();

  bubbles = std::vector<Bubble *>();

  bubbleSpawnLocation = {settings.game_size.x / 2, settings.game_size.y - 64};

  camera->offset = {25, 25};

  bubble = nullptr;

  for (int y = 32; y < 600 / settings.zoom / 2; y += 65)
  {
    for (int x = 38; x < 800 / settings.zoom - 59; x += 65)
    {
      if ((y - 32) % 130 == 0)
        bubbles.push_back(new Bubble(x + 32, y, Helpers::genRandomColor()));
      else
        bubbles.push_back(new Bubble(x, y, Helpers::genRandomColor()));
    }
  }

  for (auto bubble : bubbles)
  {
    this->addChild(bubble);
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
  DrawCircleLines(bubbleSpawnLocation.x, bubbleSpawnLocation.y, 32, WHITE);

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

    bubble->destination = {GetMouseX() / settings.zoom, GetMouseY() / settings.zoom};
    bubble->origin = {bubbleSpawnLocation.x, bubbleSpawnLocation.y};
    bubble->direction = {bubble->destination.x - bubble->origin.x, bubble->destination.y - bubble->origin.y};

    float magnitude = sqrt(bubble->direction.x * bubble->direction.x + bubble->direction.y * bubble->direction.y);
    bubble->direction.x /= magnitude;
    bubble->direction.y /= magnitude;

    bubble->shouldMove = !bubble->shouldMove;
  }

  if (bubble == nullptr)
    return;

  if (!bubble->shouldMove)
    return;

  if (bubble->position.x - 32 < 0 || bubble->position.x > settings.game_size.x - 64)
  {
    bubble->direction.x *= -1;
  }

  if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
  {
    bubble->shouldMove = false;
    removeChild(bubble);
    bubble = nullptr;
    delete bubble;
  }
}
