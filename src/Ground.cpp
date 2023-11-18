#include "Ground.h"
#include "Render.h"

Ground::Ground(SDL_Color color, Vector2 position, Vector2 size) : color(color), position(position), size(size)
{
	Init();
}

void Ground::Init()
{
	rect.x = position.x;
	rect.y = position.y;
	rect.w = size.x;
	rect.h = size.y;
}

void Ground::Draw()
{
	DrawShape(color, position.x, position.y, size.x, size.y);
}
