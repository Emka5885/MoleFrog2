#pragma once
#include <SDL_image.h>

class Cannon
{
private:
	SDL_Texture* tex;
	SDL_Rect rect;

public:
	Cannon(SDL_Texture* tex);

	void Init();

	void Draw();
};