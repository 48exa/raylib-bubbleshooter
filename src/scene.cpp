// scene.cpp

#include "scene.h"

Scene::Scene()
	: SuperScene()
{
	this->_texture = LoadTexture("../assets/test.png");
}

Scene::~Scene()
{
	delete this;
}

void Scene::update(float deltaTime)
{
	ClearBackground(RAYWHITE);

	const int texture_x = SCREEN_WIDTH / 2 - _texture.width / 2;
	const int texture_y = SCREEN_HEIGHT / 2 - _texture.height / 2;
	DrawTexture(_texture, texture_x, texture_y, WHITE);

	const char *text = "OMG! IT WORKS!";
	const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
	DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, texture_y + _texture.height + text_size.y + 10, 20, BLACK);
}