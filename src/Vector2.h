#pragma once

struct Vector2
{
	int x;
	int y;

	void operator+=(Vector2 a)
	{
		x += a.x;
		y += a.y;
	}
};