#include <bubbleshooter.h>
#include <config.h>
#include <helpers.h>

Bubbleshooter::Bubbleshooter(WindowSettings s) : Scene(s)
{

  t = new Timer();
  t->start();

  // 23x17
  bubbles = std::vector<Bubble *>();

  bubbleSpawnLocation = {settings.game_size.x / 2, settings.game_size.y - BUBBLE_SPAWN_Y_OFFSET};

  camera->offset = {CAMERA_OFFSET, CAMERA_OFFSET};

  bubble = nullptr;

  initlevel();
}

Bubbleshooter::~Bubbleshooter()
{
  for (Entity *child : this->children())
  {
    this->removeChild(child);
    child = nullptr;
    delete child;
  }
}

void Bubbleshooter::initlevel()
{
  bool visible = true;
  for (int y = Y_OFFSET; y < Y_THRESHOLD / settings.zoom; y += Y_INCREMENT)
  {
    for (int x = X_OFFSET; x < X_THRESHOLD / settings.zoom - X_EXTRA_OFFSET; x += X_INCREMENT)
    {
      if (y > (Y_THRESHOLD / settings.zoom) / 2)
        visible = false;
      if ((y - Y_OFFSET) % Y_EXTRA_OFFSET == 0)
        bubbles.push_back(new Bubble(x + X_EXTRA_OFFSET, y, visible, Helpers::genRandomColor()));
      else
        bubbles.push_back(new Bubble(x, y, visible, Helpers::genRandomColor()));
    }
  }

  for (Bubble *b : bubbles)
  {
    this->addChild(b);
  }
}

void Bubbleshooter::deleteBubble()
{
  std::cout << "Deleted Bubble with guid: " << bubble->guid() << " at position: (" << bubble->position.x << ", " << bubble->position.y << ", " << bubble->position.z << ")" << std::endl;
  bubble->shouldMove = false;
  removeChild(bubble);
  bubble = nullptr;
  delete bubble;
}

bool Bubbleshooter::outOfBounds()
{
  return {IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) || bubble->position.y < 0 || bubble->position.y > settings.game_size.y};
}

void Bubbleshooter::shootBubble(bool &bubbleCreated)
{
  bubbleCreated = true;
  if (bubble != nullptr)
    return;

  bubble = new Bubble(bubbleSpawnLocation.x, bubbleSpawnLocation.y, true, Helpers::genRandomColor());
  this->addChild(bubble);

  bubble->destination = {GetMouseAccurate().x, GetMouseAccurate().y};
  bubble->origin = {bubbleSpawnLocation.x, bubbleSpawnLocation.y};
  bubble->direction = {bubble->destination.x - bubble->origin.x, bubble->destination.y - bubble->origin.y};

  float magnitude = sqrt(bubble->direction.x * bubble->direction.x + bubble->direction.y * bubble->direction.y);
  bubble->direction.x /= magnitude;
  bubble->direction.y /= magnitude;

  bubble->shouldMove = !bubble->shouldMove;
  bubbleCreated = false;
}

void Bubbleshooter::drawGameLayout()
{
  DrawRectangle(GAME_SCREEN_OFFSET_X, GAME_SCREEN_OFFSET_Y, settings.game_size.x, settings.game_size.y, GAME_SCREEN_COLOR);
  DrawRectangleLinesEx({GAME_SCREEN_OFFSET_X, GAME_SCREEN_OFFSET_Y, settings.game_size.x, settings.game_size.y}, GAME_BORDER_THICKNESS, GAME_SCREEN_BORDER_COLOR);
  DrawCircleLines(bubbleSpawnLocation.x, bubbleSpawnLocation.y, BUBBLE_SIZE, WHITE);

  lineDirection = {GetMouseAccurate().x - bubbleSpawnLocation.x, GetMouseAccurate().y - bubbleSpawnLocation.y};

  float magnitude = sqrt(lineDirection.x * lineDirection.x + lineDirection.y * lineDirection.y);
  lineDirection.x /= magnitude;
  lineDirection.y /= magnitude;

  lineEnd = {bubbleSpawnLocation.x + lineDirection.x * AIMER_LENGTH, bubbleSpawnLocation.y + lineDirection.y * AIMER_LENGTH};

  DrawLine(bubbleSpawnLocation.x, bubbleSpawnLocation.y, lineEnd.x, lineEnd.y, WHITE);

  DrawCircle(GetMouseAccurate().x, GetMouseAccurate().y, 10, BLACK);
  // std::cout << "Mouse: (" << GetMouseAccurate().x << ", " << GetMouseAccurate().y << ")" << std::endl;
  DrawRectangle(1750, 100, 400, 150, BUTTON_COLOR);
}

void Bubbleshooter::test(Vector2 coords)
{

  if (coords.x > 23)
    crash("X coordinate out of bounds when indexing array");

  if (coords.y > 17)
    crash("Y coordinate out of bounds when indexing array");

  int index = (coords.x) + (coords.y * 24);

  if (IsKeyPressed(KEY_E))
  {
    bubbles[index]->visible = !bubbles[index]->visible;
  }
}

Vector2 Bubbleshooter::GetMouseAccurate()
{
  return Vector2{GetMouseX() / settings.zoom - MOUSE_OFFSET, GetMouseY() / settings.zoom - MOUSE_OFFSET};
}

void Bubbleshooter::update(float deltaTime)
{
  drawGameLayout();

  if (IsKeyPressed(KEY_Q))
  {
    this->toggleVsync();
  }

  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
  {
    bool bubbleCreated;
    shootBubble(bubbleCreated);
    if (bubbleCreated)
      return;
  }

  if (bubble == nullptr)
    return;

  if (bubble->position.x - 32 < 0 || bubble->position.x > settings.game_size.x - 64)
    bubble->bounce();

  for (Bubble *b : bubbles)
  {
    if (!b->visible)
      continue;

    if (CheckCollisionCircles({b->position.x, b->position.y}, BUBBLE_SIZE, {bubble->position.x, bubble->position.y}, 32))
    {
      if (b->visible)
        bubble->shouldMove = false;
    }
  }

  if (outOfBounds())
    deleteBubble();
}