#include "Widgets.h"
#include "Render.h"
#include <iostream>

Widgets::Widgets(TTF_Font* font, const char* text) : font(font), text(text)
{
	Init();
}

void Widgets::Init()
{
	fontColor = { 0,0,0,255 };
}

void Widgets::SetTextValue(const char* newText)
{
	textValue = newText;
}

void Widgets::Draw()
{
	DrawText(font, fontColor, text, 10, 10, textWidth);
	DrawText(font, fontColor, textValue, 10 + textWidth, 10);
}
