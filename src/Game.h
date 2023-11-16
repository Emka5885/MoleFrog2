#pragma once
#include <vector>
#include "AssetManager.h"
#include "InputManager.h"
#include "Button.h"
#include "Cannon.h"
#include "Data.h"

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

	Cannon* cannon;
	Button* fireButton;

	std::vector<Data*> data;

	int delayOfClickedMouseButton = 3;
	bool mouseButtonClicked = false;
	bool quitt = false;
};