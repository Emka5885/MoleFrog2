#include "Cannon.h"
#include "Definitions.h"
#include "Render.h"

Cannon::Cannon(SDL_Texture* tex) : tex(tex)
{
	Init();
}

void Cannon::Init()
{
	rect.x = CANNON_POSITION_X;
	rect.y = CANNON_POSITION_Y;
	rect.w = CANNON_SIZE_X;
	rect.h = CANNON_SIZE_Y;
}

void Cannon::Draw()
{
	DrawObject(tex, rect.x, rect.y, rect.w, rect.h);
}
