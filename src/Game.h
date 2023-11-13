#pragma once
#include <vector>
#include "AssetManager.h"

class Game
{
public:
	Game();
	~Game();
	void Init();
	void Loop();
	void Input();
	void Update();
	void Draw();

private:
	AssetManager* assets;

	bool quitt = false;
};