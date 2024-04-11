#include <cashcollector.h>

CashCollector::CashCollector(Rectangle collector) : Entity() {
  this->collector = {collector.x, collector.y, collector.width, collector.height};
  label = "Pick up cash";
  btnColor = GREEN;
  outlineColor = DARKGREEN;
  cash = 0;
}

CashCollector::~CashCollector() {
}

void CashCollector::update(float deltaTime) {
  label = TextFormat("Pick up cash: %s", formatCash(cash));

  collector.x = 0 - collector.width / 2;

  if (collector.width < (float)MeasureText(label, 10) + 6) {
    collector.width = (float)MeasureText(label, 10) + 6;
  };

  DrawRectangle(collector.x, collector.y, collector.width, collector.height, btnColor);
  DrawRectangleLines(collector.x, collector.y, collector.width, collector.height, outlineColor);
  DrawText(label, collector.x + 3, collector.y + 3, 10, WHITE);

  changeButtonColor();

  if (isStoodOn()) {
    sendCash();
  }
}

void CashCollector::update_static(float deltaTime) {
}

void CashCollector::sendCash() {
  *balanceptr += cash;
  cash = 0;
}

void CashCollector::sendBalptr(double *balptr) {
  this->balanceptr = balptr;
}

void CashCollector::changeButtonColor() {
  if (isStoodOn()) {
    btnColor = DARKGREEN;
    outlineColor = GREEN;
  } else {
    btnColor = GREEN;
    outlineColor = DARKGREEN;
  }
}

bool CashCollector::isStoodOn() {
  return CheckCollisionRecs(playerHB, collector);
}

void CashCollector::sendHitbox(Player **p) {
  playerHB = {(*p)->position.x - 8,
              (*p)->position.y - 8,
              (*p)->spriteSize,
              (*p)->spriteSize};
}

const char *CashCollector::formatCash(double $) {
  const char *formatted = TextFormat("$%.0f", $);

  if ($ > 1000) {
    formatted = TextFormat("$%.1fk", $ / 1000);
  }
  if ($ > 1000000) {
    formatted = TextFormat("$%.2fm", $ / 1000000);
  }
  if ($ > 1000000000) {
    formatted = TextFormat("$%.1e", $);
  }

  return formatted;
}

void CashCollector::addCash(double $) {
  cash += $;
}
