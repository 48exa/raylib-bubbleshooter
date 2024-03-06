#include <bubbleshooter.h>
#include <config.h>

Bubbleshooter::Bubbleshooter(WindowSettings settings) : Scene(settings)
{
  t = new Timer();
  t->start();

  bubble = new Bubble();

  bubble->addTexture("../../assets/bubble.png");
  bubble->position.x = settings.dimensions.width / 2.0f;
  bubble->position.y = settings.dimensions.height / 2.0f;
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

  if (IsKeyPressed(KEY_Q))
  {
    this->toggleVsync();
  }

  if (t->getSeconds() > 0.1f)
  {
    switch (rand() % 3)
    {
    case 0:
      bubble->setTextureColor(BLUE);
      t->restart();
      break;
    case 1:
      bubble->setTextureColor(GREEN);
      t->restart();
      break;
    case 2:
      bubble->setTextureColor(RED);
      t->restart();
      break;
    case 3:
      bubble->setTextureColor(YELLOW);
      t->restart();
      break;
    }
  }

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
  if (bubble->position.x + bubble->size().x > settings.dimensions.width)
  {
    bubble->position.x = settings.dimensions.width - bubble->size().x;
  }
  if (bubble->position.y + bubble->size().y > settings.dimensions.height)
  {
    bubble->position.y = settings.dimensions.height - bubble->size().y;
  }
}
