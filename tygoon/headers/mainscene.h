#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <cashcollector.h>
#include <conveyor.h>
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
  void drawStats();
  void cameraClamp();
  void updateCamera(float deltaTime);
  void drawCoordinates();
  void drawBalance();
  void addBalance(unsigned long *amount);
  void drawMap();
  void drawMapBorder();

  double *balance;
  CashCollector *collector;
  Player *player;
  Timer *t;
  Conveyor *conveyor;

  Color bg = {0, 0, 0, 100};
  Color outline = {255, 255, 255, 100};
  Color textCol = {230, 230, 230, 255};
  int height = 35;
  int topLeft = 3;
};

#endif