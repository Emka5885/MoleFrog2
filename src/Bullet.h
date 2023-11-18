#pragma once
#include <SDL.h>
#include "Collider.h"
#include "Vector2.h"

class Bullet
{
private:
	SDL_Texture* tex;
	SDL_Rect rect;
	Vector2 currentPos;
	Vector2 initialPos;
	int ang, is, grav, ad;
	float rad, vx, vy, v0x, v0y, t;

	Collider* collider;

public:
	Bullet(SDL_Texture* tex, Vector2 initialPos, int ang, int is, int grav, int ad);

	void Init();
	void SetPositon();
	void CalculateNewPosition(float dt);

	void Draw();

	bool GetIfHitGround(SDL_Rect& ground);
	int GetDistanceTraveled();
};