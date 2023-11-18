#pragma once
#include <SDL.h>
#include "Vector2.h"

class Collider
{
public:
	Collider() {}

	bool CheckCollisionOfObjectAndPoint(SDL_Rect& object, Vector2& point);
	bool CheckCollisionOfObjects(SDL_Rect& object, SDL_Rect& object2);
};