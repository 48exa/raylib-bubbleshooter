// scene.h

#ifndef SCENE_H
#define SCENE_H

#include "../framework/superscene.h"

class Scene : public SuperScene
{
public:
	Scene();
	virtual ~Scene();
	virtual void update(float deltaTime);

private:
	Texture2D _texture;
};

#endif /* SCENE_H */
