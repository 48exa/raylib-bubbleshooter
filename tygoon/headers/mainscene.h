#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <cashcollector.h>
#include <player.h>
#include <scene.h>
#include <timer.h>

class MainScene : public Scene {
public:
  MainScene(WindowSettings s);
  ~MainScene();

  void update(float deltaTime) override;
  void update_static(float deltaTime) override;

private:
  void updateCamera(float deltaTime);
  void drawCoordinates();
  void drawBalance();
  void addBalance(unsigned long *amount);

  double balance;
  CashCollector *collector;
  Player *player;
  Timer *t;
};

#endif