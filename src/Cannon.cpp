#include "Cannon.h"
#include "Definitions.h"
#include "Render.h"

Cannon::Cannon(SDL_Texture* tex, int ang) : tex(tex), ang(ang)
{
	Init();
}

void Cannon::Init()
{
	rect.x = CANNON_POSITION_X;
	rect.y = CANNON_POSITION_Y;
	rect.w = CANNON_SIZE_X;
	rect.h = CANNON_SIZE_Y;

	center = { rect.w / 2, rect.h / 2 };
}

void Cannon::Fire(AssetManager* assets, int is, int grav, int ad)
{
	if (bullet != nullptr)
		delete bullet;

	bullet = new Bullet(assets->GetTexture(BULLET), { CANNON_POSITION_X + CANNON_SIZE_X / 2 - BULLET_SIZE / 2, CANNON_POSITION_Y + CANNON_SIZE_Y / 2 - BULLET_SIZE / 2 }, ang, is, grav, ad);
}

void Cannon::SetNewAngle(int a)
{
	ang = a;
}

void Cannon::Draw()
{
	if (bullet != nullptr)
	{
		bullet->Draw();
	}

	DrawCannon(tex, rect.x, rect.y, rect.w, rect.h, 90 - ang - CANNON_ROTATION, center);
}
