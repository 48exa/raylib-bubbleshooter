#include <mainscene.h>

MainScene::MainScene(WindowSettings s) : Scene(s) {
  player = new Player(s);
  collector = new CashCollector({0, 0, 16, 16});
  t = new Timer();

  addChild(collector);

  balance = 0.0f;
  collector->sendBalptr(&balance);
}

MainScene::~MainScene() {
}

void MainScene::update(float deltaTime) {
  // manually updating for layering
  collector->sendHitbox(&player);
  collector->update(deltaTime);
  player->update(deltaTime);

  updateCamera(deltaTime);

  if (!collector->isStoodOn()) {
    collector->addCash(10000 * deltaTime);
  };

  // DrawLineEx({collector->position.x + 50, collector->position.y}, {player->position.x, player->position.y}, 3, WHITE);
}

void MainScene::update_static(float deltaTime) {
  drawCoordinates();
  drawBalance();
}

void MainScene::drawBalance() {
  const char *text = collector->formatCash(balance);
  float width = MeasureText(text, 25) + 10;
  int height = 35;
  Color bg = {0, 0, 0, 100};
  Color outline = {255, 255, 255, 100};
  Color textCol = {230, 230, 230, 255};

  float topRight = settings.size.x - width - 3;

  DrawRectangle(topRight, 3, width, height, bg);
  DrawRectangleLines(topRight, 3, width, 35, outline);
  DrawText(text, topRight + 5, 10, 25, textCol);
}

void MainScene::drawCoordinates() {
  float posX = player->position.x / 8;
  float posY = player->position.y / 8;
  const char *coords = TextFormat("x: %.0f y: %.0f", posX, posY);
  float width = MeasureText(coords, 20) + 20;
  int height = 35;
  Color bg = {0, 0, 0, 100};
  Color outline = {255, 255, 255, 100};
  Color textCol = {230, 230, 230, 255};

  DrawRectangle(3, 3, width, height, bg);
  DrawRectangleLines(3, 3, width, 35, outline);
  DrawText(coords, 12, 10, 20, textCol);
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
}