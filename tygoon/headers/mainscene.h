#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <scene.h>

class MainScene : public Scene {
public:
  MainScene(WindowSettings s);
  ~MainScene();

  void update(float deltaTime) override;

private:
};

#endif