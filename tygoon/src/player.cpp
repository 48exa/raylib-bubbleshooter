#include <player.h>

Player::Player(WindowSettings s) : AnimatedEntity() {
  settings = s;

  t = new Timer();
  t->start();

  spriteCount = 2;
  spriteSize = 16.0f;
  spriteTime = 0.125f;
  spriteIndex = 0;
  spriteStartIndex = 0;

  lastDirectionMoved = 0;

  this->addTexture("assets/tygooner.png");
}

Player::~Player() {
}

void Player::update(float deltaTime) {
  Rectangle source = {(float)spriteIndex * spriteSize, 0, spriteSize, spriteSize};
  Rectangle dest = {position.x, position.y, spriteSize, spriteSize};
  Vector2 origin = {dest.width / 2, dest.height / 2};

  move(deltaTime);
  drawShadow();
  DrawTexturePro(texture(), source, dest, origin, 0, color());

  if (t->getSeconds() > spriteTime) {
    spriteIndex++;
    if (spriteIndex >= spriteCount) {
      spriteIndex = spriteStartIndex;
    }
    t->restart();
  }
};

void Player::showIdleSprite() {

  switch (lastDirectionMoved) {
  case 1:
    spriteCount = 10;
    spriteIndex = 10;
    spriteStartIndex = 10;
    break;
  case 2:
    spriteCount = 12;
    spriteIndex = 12;
    spriteStartIndex = 12;
    break;
  case 3:
    spriteCount = 8;
    spriteIndex = 8;
    spriteStartIndex = 8;
    break;
  case 4:
    spriteCount = 11;
    spriteIndex = 11;
    spriteStartIndex = 11;
    break;
  }
}

void Player::drawShadow() {
  DrawEllipse(position.x, position.y + spriteSize / 2.2f, spriteSize / 3.0f, spriteSize / 6.0f, {0, 0, 0, 50});
}

void Player::move(float deltaTime) {
  normalizeMovement(deltaTime);

  if (IsKeyDown(KEY_W)) {
    position.y -= speed * deltaTime;
    lastDirectionMoved = 1;
    animate(UP);
  }

  if (IsKeyDown(KEY_A)) {
    position.x -= speed * deltaTime;
    animate(LEFT);
    lastDirectionMoved = 2;
  }

  if (IsKeyDown(KEY_S)) {
    position.y += speed * deltaTime;
    animate(DOWN);
    lastDirectionMoved = 3;
  }

  if (IsKeyDown(KEY_D)) {
    position.x += speed * deltaTime;
    animate(RIGHT);
    lastDirectionMoved = 4;
  }
}

void Player::animate(std::string direction) {
  static std::string lastDirection = "";

  if (direction == lastDirection) {
    return;
  }

  lastDirection = direction;

  if (direction == "up") {
    spriteCount = 4;
    spriteIndex = 2;
    spriteStartIndex = 2;
  } else if (direction == "down") {
    spriteCount = 2;
    spriteIndex = 0;
    spriteStartIndex = 0;
  } else if (direction == "left") {
    spriteCount = 8;
    spriteIndex = 6;
    spriteStartIndex = 6;
  } else if (direction == "right") {
    spriteCount = 6;
    spriteIndex = 4;
    spriteStartIndex = 4;
  }
}

void Player::normalizeMovement(float deltaTime) {
  float dx = 0;
  float dy = 0;

  if (IsKeyDown(KEY_W)) {
    dy -= 1;
  }

  if (IsKeyDown(KEY_A)) {
    dx -= 1;
  }

  if (IsKeyDown(KEY_S)) {
    dy += 1;
  }

  if (IsKeyDown(KEY_D)) {
    dx += 1;
  }

  // Normalize diagonal movement
  if (dx != 0 && dy != 0) {
    float length = sqrt(dx * dx + dy * dy);
    dx /= length;
    dy /= length;
  }

  position.x += dx * speed * deltaTime;
  position.y += dy * speed * deltaTime;
}
