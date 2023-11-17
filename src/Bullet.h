#pragma once
#include <SDL.h>
#include <vector>
#include "Data.h"
#include "Vector2.h"

class Bullet
{
private:
	SDL_Texture* tex;
	SDL_Rect rect;
	Vector2 currentPos;
	std::vector<Data*> data;

public:
	Bullet(SDL_Texture* tex, Vector2 initialPos, std::vector<Data*> data);

	void Init();
	void SetPositon();

	void Draw();
};