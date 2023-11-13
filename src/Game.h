#pragma once
#include <vector>
#include "AssetManager.h"
#include "InputManager.h"
#include "Button.h"

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
	InputManager* input;

	Button* fireButton;

	bool quitt = false;
};