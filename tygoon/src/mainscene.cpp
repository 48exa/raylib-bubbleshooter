#include <mainscene.h>

MainScene::MainScene(WindowSettings s) : Scene(s) {
  player = new Player(s);
  collector = new CashCollector({0, 0, 16, 16});
  conveyor = new Conveyor({-175, -150, 350, 50});

  t = new Timer();
  t->start();

  _items = std::vector<Item *>();
  _spawners = std::vector<Spawner *>();

  _spawners.push_back(new Spawner({-170, -125, 0}, &_items, 75, 5.0f));
  _spawners.push_back(new Spawner({-120, -125, 0}, &_items, 500, 10.0f));
  _spawners.push_back(new Spawner({-70, -125, 0}, &_items, 1500, 25.0f));
  _spawners.push_back(new Spawner({-20, -125, 0}, &_items, 5000, 45.0f));
  _spawners.push_back(new Spawner({30, -125, 0}, &_items, 10000, 100.0f));
  _spawners.push_back(new Spawner({80, -125, 0}, &_items, 15000, 233.0f));
  _spawners.push_back(new Spawner({130, -125, 0}, &_items, 999900, 25000.0f));

  addChild(collector);
  addChild(conveyor);

  _balanceptr = player->getBalancePtr();
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

  updateCamera(deltaTime);

  drawItems(deltaTime);
  drawSpawners(deltaTime);

  player->update(deltaTime);
}

void MainScene::update_static(float deltaTime) {
  drawCoordinates();
  drawBalance();
  drawStats();
  drawMouseDebug();
}

void MainScene::drawSpawners(float deltaTime) {
  if (_spawners.size() > 0) {
    for (signed int i = 0; i < _spawners.size(); i++) {
      if (!_spawners[i]->isActive()) {
        if (CheckCollisionRecs(player->getHitbox(), {_spawners[i]->position.x, _spawners[i]->position.y + 16, 16, 16})) {
          if (*_balanceptr >= _spawners[i]->cost) {
            *_balanceptr -= _spawners[i]->cost;
            _spawners[i]->setActive();
          }
        }
      }

      if (_spawners[i] == nullptr) {
        delete _spawners[i];
        continue;
      }
      _spawners[i]->update(deltaTime);
    }
  }
};

void MainScene::drawItems(float deltaTime) {
  if (_items.size() > 0) {
    for (signed int i = 0; i < _items.size(); i++) {
      if (_items[i] == nullptr) {
        delete _items[i];
        continue;
      }

      _items[i]->update(deltaTime);

      if (CheckCollisionRecs(conveyor->conveyor, _items[i]->getHitbox())) {
        _items[i]->item.x += 100 * deltaTime;
      }

      if (CheckCollisionRecs(conveyor->itemCollector, _items[i]->getHitbox())) {
        collector->addCash(_items[i]->getValue());
        _items[i] = nullptr;
      }
    }
  }
}

void MainScene::drawMouseDebug() {
  Vector2 mouse = GetMousePosition();
  DrawText(TextFormat("x: %.0f y: %.0f", player->position.x, player->position.y), mouse.x - 10, mouse.y - 10, 20, WHITE);
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
  // Center lines
  // DrawLine(-2000, (h / 2 + y), 2000, (h / 2 + y), BLACK);
  // DrawLine((w / 2 + x), -2000, (w / 2 + x), 2000, BLACK);
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