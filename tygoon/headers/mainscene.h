#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <cashcollector.h>
#include <conveyor.h>
#include <item.h>
#include <player.h>
#include <scene.h>
#include <spawner.h>
#include <timer.h>
#include <vector>
#include <command.h>

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

  void drawMouseDebug();
  void drawItems(float deltaTime);
  void drawSpawners(float deltaTime);

  double *_balanceptr;

  std::vector<Item *> _items;
  std::vector<Spawner *> _spawners;

  Command *cmd;
  CashCollector *collector;
  Player *player;
  Timer *t;
  Conveyor *conveyor;
  Spawner *spawner;

  Color bg = {0, 0, 0, 100};
  Color outline = {255, 255, 255, 100};
  Color textCol = {230, 230, 230, 255};
  int height = 35;
  int topLeft = 3;
};

#endif