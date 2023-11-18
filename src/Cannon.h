#pragma once
#include <SDL_image.h>
#include "AssetManager.h"
#include "Bullet.h"
class Cannon
{
private:
	SDL_Texture* tex;
	SDL_Rect rect;
	int ang = 0;
	SDL_Point center;

	Bullet* bullet;

public:
	Cannon(SDL_Texture* tex, int ang);

	void Init();
	void Fire(AssetManager* assets, int is, int grav, int ad);

	void SetNewAngle(int a);

	void Draw();

	Bullet* GetBullet() { return bullet; }
};