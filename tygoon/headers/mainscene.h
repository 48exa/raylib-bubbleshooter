#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <cashcollector.h>
#include <command.h>
#include <conveyor.h>
#include <item.h>
#include <player.h>
#include <scene.h>
#include <spawner.h>
#include <string>
#include <timer.h>
#include <unordered_map>
#include <vector>

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
  void addCash(unsigned long amount);

  void drawCoordinates();
  void drawBalance();
  void drawMap();
  void drawMapBorder();
  void drawCommandBox();
  void drawMouseDebug();
  void drawItems(float deltaTime);
  void drawSpawners(float deltaTime);

  double *_balanceptr;
  double *_collectorCashPtr;

  std::vector<Item *> _items;
  std::vector<Spawner *> _spawners;

  std::unordered_map<std::string, Command *> commands;

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
  char name[256];
  int letterCount = 0;

  bool commandMode;

  Sound fart = LoadSound("assets/pokimane.wav");
};

#endif