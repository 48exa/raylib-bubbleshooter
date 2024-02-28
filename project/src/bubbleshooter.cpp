#include <bubbleshooter.h>

Bubbleshooter::Bubbleshooter(uint16_t width, uint16_t height, char *title)
    : Scene(width, height, title)
{
  t = new Timer();
  t->start();

  bubble = new Bubble();

  bubble->addTexture("../assets/dev.png");
  bubble->position.x = SCREEN_WIDTH / 2;
  bubble->position.y = SCREEN_HEIGHT / 2;
  bubble->setTextureColor(WHITE);

  this->addChild(bubble);
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
  if (IsKeyDown(KEY_W))
  {
    bubble->position.y -= 750 * deltaTime;
  }
  if (IsKeyDown(KEY_A))
  {
    bubble->position.x -= 750 * deltaTime;
  }
  if (IsKeyDown(KEY_S))
  {
    bubble->position.y += 750 * deltaTime;
  }
  if (IsKeyDown(KEY_D))
  {
    bubble->position.x += 750 * deltaTime;
  }

  if (bubble->position.x < 0)
  {
    bubble->position.x = 0;
  }
  if (bubble->position.y < 0)
  {
    bubble->position.y = 0;
  }
  if (bubble->position.x + bubble->size().x > SCREEN_WIDTH)
  {
    bubble->position.x = SCREEN_WIDTH - bubble->size().x;
  }
  if (bubble->position.y + bubble->size().y > SCREEN_HEIGHT)
  {
    bubble->position.y = SCREEN_HEIGHT - bubble->size().y;
  }
}