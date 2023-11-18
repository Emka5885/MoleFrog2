#include "Bullet.h"
#include "Definitions.h"
#include "Render.h"

Bullet::Bullet(SDL_Texture* tex, Vector2 initialPos, int ang, int is, int grav, int ad) : tex(tex), initialPos(initialPos), ang(ang), is(is), grav(grav), ad(ad)
{
	Init();
}

void Bullet::Init()
{
	currentPos = initialPos;

	rad = ang * PI / 180;

	rect.w = rect.h = BULLET_SIZE;
	SetPositon();

	v0x = vx = is * cos(rad);
	v0y = vy = is * sin(rad);
	t = 0;
}

void Bullet::SetPositon()
{
	rect.x = static_cast<int>(currentPos.x);
	rect.y = static_cast<int>(currentPos.y);
}

void Bullet::CalculateNewPosition(float dt)
{
	t += dt;

	int newPosX = initialPos.x + vx * t;
	if (newPosX > currentPos.x)
	{
		currentPos.x = newPosX;
	}
	currentPos.y = initialPos.y - vy * t + (grav+ad) * t * t / 2;
	SetPositon();

	vx -= ad * dt;
	vy -= (grav+ad) * dt;
}

bool Bullet::GetIfHitGround(SDL_Rect& ground)
{
	return collider->CheckCollisionOfObjects(rect, ground);
}

int Bullet::GetDistanceTraveled()
{
	return currentPos.x - initialPos.x;
}

void Bullet::Draw()
{
	DrawObject(tex, rect.x, rect.y, rect.w, rect.h);
}
