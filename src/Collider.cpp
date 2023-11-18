#include "Collider.h"
#include <iostream>

bool Collider::CheckCollisionOfObjectAndPoint(SDL_Rect& object, Vector2& point)
{
	// left
	if (object.x > point.x)
	{
		return false;
	}
	// right
	if (object.x + object.w < point.x)
	{
		return false;
	}
	// top
	if (object.y > point.y)
	{
		return false;
	}
	// bottom
	if (object.y + object.h < point.y)
	{
		return false;
	}

	return true;
}

bool Collider::CheckCollisionOfObjects(SDL_Rect& object, SDL_Rect& object2)
{
	int counter = 0;
	// left
	if (object.x < object2.x + object2.w)
	{
		counter++;
	}
	// right
	if(object.x + object.w > object2.x)
	{
		counter++;
	}
	// top
	if (object.y < object2.h + object2.y)
	{
		counter++;
	}
	if(object.y + object.h > object2.y )
	{
		counter++;
	}

	if (counter == 4)
		return true;

	return false;
}
