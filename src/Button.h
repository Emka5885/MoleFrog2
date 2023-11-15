#pragma once
#include <SDL.h>
#include "Collider.h"
#include "Definitions.h"
#include "Vector2.h"
#include "AssetManager.h"
#include <string>

class Button
{
private:
	int outline;
	SDL_Rect rect;
	SDL_Color outlineColor;
	SDL_Color unhoverColor;
	SDL_Color hoverColor;
	SDL_Color clickColor;
	Vector2 unhoverSize;
	Vector2 hoverSize;
	Vector2 unhoverPosition;
	Vector2 hoverPosition;
	ButtonTypes buttonType;
	const char* buttonText;

	Collider* collider;

public:
	Button(Vector2 unhoverSize, Vector2 unhoverPosition, SDL_Color unhoverColor, SDL_Color outlineColor, const char* buttonText, int zoom = 4);

	void Init(int zoom);
	void CheckIfClicked(Vector2 mousePos);
	void CheckIfHovered(Vector2 mousePos);
	void ChangeHover();
	void SetClicked();

	void Draw(AssetManager* assets);

	SDL_Color GetCurrentColor();
	Vector2& GetCurrentPosition();
	Vector2& GetCurrentSize();
};