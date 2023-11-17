#include "Bullet.h"
#include "Definitions.h"
#include "Render.h"

Bullet::Bullet(SDL_Texture* tex, Vector2 initialPos, std::vector<Data*> data) : tex(tex), currentPos(initialPos), data(data)
{
	Init();
}

void Bullet::Init()
{
	rect.w = rect.h = BULLET_SIZE;
	SetPositon();
}

void Bullet::SetPositon()
{
	rect.x = currentPos.x;
	rect.y = currentPos.y;
}

void Bullet::Draw()
{
	DrawObject(tex, rect.x, rect.y, rect.w, rect.h);
}
