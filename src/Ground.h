#pragma once
#include <SDL.h>
#include "Vector2.h"

class Ground
{
private:
	SDL_Color color;
	Vector2 position, size;
	SDL_Rect rect;

public:
	Ground(SDL_Color color, Vector2 position, Vector2 size);

	void Init();
	void Draw();

	SDL_Rect& GetRect() { return rect; }
};