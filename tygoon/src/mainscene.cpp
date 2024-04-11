#include <mainscene.h>

MainScene::MainScene(WindowSettings s) : Scene(s) {
  player = new Player(s);
  collector = new CashCollector({0, 0, 16, 16});
  conveyor = new Conveyor({-175, -150, 350, 50});
  t = new Timer();

  addChild(collector);
  addChild(conveyor);
  addChild(player);

  balance = player->getBalancePtr();
  collector->sendBalptr(player->getBalancePtr());
}

MainScene::~MainScene() {
}

void MainScene::update(float deltaTime) {
  // manually updating for layering
  drawMap();

  for (Entity *child : children()) {
    child->update(deltaTime);
  }

  collector->sendHitbox(&player);
  conveyor->sendHitbox(&player);
  // player->update(deltaTime);

  updateCamera(deltaTime);

  if (!collector->isStoodOn()) {
    collector->addCash(10 * deltaTime);
  };

  if (CheckCollisionRecs(conveyor->itemCollector, player->getHitbox())) {
    collector->addCash(rand() % 1000 * deltaTime);
  }
}

void MainScene::update_static(float deltaTime) {
  drawCoordinates();
  drawBalance();
  drawStats();
}

void MainScene::drawStats() {
  if (player->sprinting()) {
    const char *text = "Sprinting";
    DrawText(text, settings.size.x, settings.size.y, 20, WHITE);
    float width = MeasureText(text, 20) + 40;

    DrawRectangle(3, settings.size.y - 40, width, height, bg);
    DrawRectangleLines(3, settings.size.y - 40, width, 35, outline);
    DrawText(text, 3 + 5, settings.size.y - 35, 25, textCol);
  }
}

void MainScene::drawBalance() {
  const char *text = collector->formatCash(*player->getBalancePtr());
  float width = MeasureText(text, 25) + 10;
  float topRight = settings.size.x - width - 3;

  DrawRectangle(topRight, topLeft, width, height, bg);
  DrawRectangleLines(topRight, topLeft, width, 35, outline);
  DrawText(text, topRight + 5, 10, 25, textCol);
}

void MainScene::drawCoordinates() {
  float posX = player->position.x / 8;
  float posY = player->position.y / 8;
  const char *text = TextFormat("x: %.0f y: %.0f", posX, posY);
  float width = MeasureText(text, 20) + 20;

  DrawRectangle(3, 3, width, height, bg);
  DrawRectangleLines(3, 3, width, 35, outline);
  DrawText(text, 12, 10, 20, textCol);
}

void MainScene::drawMapBorder() {
  signed int x, y, w, h;
  x = -565;
  y = -357;
  w = 1130;
  h = 713;
  DrawRectangle(x, y, w, h, BROWN);
  DrawLine(-2000, (h / 2 + y), 2000, (h / 2 + y), BLACK);
  DrawLine((w / 2 + x), -2000, (w / 2 + x), 2000, BLACK);
}

void MainScene::drawMap() {
  drawMapBorder();
}

void MainScene::updateCamera(float deltaTime) {
  camera->offset = {settings.size.x / 2, settings.size.y / 2};
  camera->target = {player->position.x, player->position.y};

  float wheel = GetMouseWheelMove();
  if (wheel != 0) {
    const float zoomIncrement = 1.0f;
    const float zoomMax = 10.0f;

    camera->zoom += (wheel * zoomIncrement);
    if (camera->zoom < zoomIncrement) {
      camera->zoom = zoomIncrement;
    }
    if (camera->zoom > zoomMax) {
      camera->zoom = zoomMax;
    }
  }
  cameraClamp();
}

void MainScene::cameraClamp() {
  if (player->position.y < -345) {
    player->position.y = -345;
  }
  if (player->position.y > 340) {
    player->position.y = 340;
  }
  if (player->position.x < -550) {
    player->position.x = -550;
  }
  if (player->position.x > 555) {
    player->position.x = 555;
  }
}