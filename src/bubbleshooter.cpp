#include <bubbleshooter.h>

Bubbleshooter::Bubbleshooter(uint16_t width, uint16_t height, std::string title)
    : Scene(width, height, title)
{
  t = new Timer();
  t->start();

  entity->addTexture("../assets/test.png");
  entity->position.x = SCREEN_WIDTH / 2;
  entity->position.y = SCREEN_HEIGHT / 2;
  entity->setTextureColor(WHITE);

  // this->addChild(entity); // broken, dk why
}

Bubbleshooter::~Bubbleshooter()
{
}

void Bubbleshooter::update(float deltaTime)
{
  // DrawText("Bubble shoot", 10, 30, 40, WHITE);
  DrawTexture(entity->texture(), entity->position.x, entity->position.y, entity->color());

  if (IsKeyDown(KEY_W))
  {
    entity->position.y -= 750 * deltaTime;
  }
  if (IsKeyDown(KEY_A))
  {
    entity->position.x -= 750 * deltaTime;
  }
  if (IsKeyDown(KEY_S))
  {
    entity->position.y += 750 * deltaTime;
  }
  if (IsKeyDown(KEY_D))
  {
    entity->position.x += 750 * deltaTime;
  }

  if (entity->position.x < 0)
  {
    entity->position.x = 0;
  }
  if (entity->position.y < 0)
  {
    entity->position.y = 0;
  }
  if (entity->position.x + entity->size().x > SCREEN_WIDTH)
  {
    entity->position.x = SCREEN_WIDTH - entity->size().x;
  }
  if (entity->position.y + entity->size().y > SCREEN_HEIGHT)
  {
    entity->position.y = SCREEN_HEIGHT - entity->size().y;
  }
}