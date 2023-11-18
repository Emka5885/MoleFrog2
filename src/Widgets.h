#pragma once
#include <SDL.h>
#include <SDL_ttf.h>

class Widgets
{
private:
	TTF_Font* font;
	SDL_Color fontColor;
	const char* text;
	const char* textValue;
	int textWidth;

public:
	Widgets(TTF_Font* font, const char* text);

	void Init();
	void SetTextValue(const char* newText);

	void Draw();
};