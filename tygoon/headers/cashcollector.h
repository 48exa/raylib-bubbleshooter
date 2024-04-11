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
  static const char *formatCash(double $);

  Rectangle collector;

private:
  void sendCash();
  void changeButtonColor();

  double *balanceptr;

  Rectangle playerHB;
  Color btnColor;
  Color outlineColor;
  double cash;
  const char *label;
};

#endif