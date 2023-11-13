#include "Collider.h"

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
