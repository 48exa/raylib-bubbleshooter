// superscene.h

#ifndef SUPERSCENE_H
#define SUPERSCENE_H

#include "raylib.h"
#include "global.h"
class SuperScene
{
public:
	SuperScene();
	virtual ~SuperScene();
	virtual void update(float deltaTime) = 0;

private:
	/* add your private declarations */
};

#endif /* SUPERSCENE_H */
