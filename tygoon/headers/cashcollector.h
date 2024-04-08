#ifndef CASHCOLLECTOR_H
#define CASHCOLLECTOR_H

#include <entity.h>
#include <player.h>

class CashCollector : public Entity {
public:
  CashCollector(Rectangle collector);
  ~CashCollector();

  void update(float deltaTime) override;
  void update_static(float deltaTime);
  void sendHitbox(Player **p);
  void sendBalptr(double *balptr);
  void addCash(double $);
  bool isStoodOn();
  const char *formatCash(double $);

private:
  void sendCash();
  void changeButtonColor();

  double *balptr;
  Rectangle collector;
  Rectangle playerHB;
  Color btnColor;
  Color outlineColor;
  double cash;
  const char *label;
};

#endif