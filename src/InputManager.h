#pragma once
#include <SDL.h>
#include "Vector2.h"

class InputManager
{
public:
	InputManager() {}

	Vector2 GetMousePosition();
};