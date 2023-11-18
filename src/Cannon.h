#pragma once
#include <SDL_image.h>
#include <vector>
#include "AssetManager.h"
#include "Bullet.h"
#include "Data.h"

class Cannon
{
private:
	SDL_Texture* tex;
	SDL_Rect rect;

	Bullet* bullet;

public:
	Cannon(SDL_Texture* tex);

	void Init();
	void Fire(AssetManager* assets, std::vector<Data*> data);

	void Draw();

	Bullet* GetBullet() { return bullet; }
};