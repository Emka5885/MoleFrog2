#include "Button.h"
#include <algorithm>
#include "Definitions.h"
#include "Render.h"

Button::Button(Vector2 unhoverSize, SDL_Color unhoverColor, SDL_Color outlineColor, SDL_Color fontColor, const char* buttonText, TTF_Font* font, int zoom, Vector2 unhoverPosition, bool changeColorWhenClicked) : unhoverSize(unhoverSize), unhoverPosition(unhoverPosition), unhoverColor(unhoverColor), outlineColor(outlineColor), fontColor(fontColor), buttonText(buttonText), font(font), zoom(zoom), changeColorWhenClicked(changeColorWhenClicked)
{
	collider = new Collider();
	Init();
}

void Button::Init()
{
	buttonType = unhovered;

	outline = DEFAULT_OUTLINE;

	unhoverColor.r = std::clamp(int(unhoverColor.r), 45, 255);
	unhoverColor.g = std::clamp(int(unhoverColor.g), 45, 255);
	unhoverColor.b = std::clamp(int(unhoverColor.b), 45, 255);

	hoverColor.r = unhoverColor.r - 25;
	hoverColor.g = unhoverColor.g - 25;
	hoverColor.b = unhoverColor.b - 25;

	clickColor.r = unhoverColor.r - 45;
	clickColor.g = unhoverColor.g - 45;
	clickColor.b = unhoverColor.b - 45;

	unhoverPosition.x -= unhoverSize.x / 2;
	unhoverPosition.y -= unhoverSize.y / 2;

	hoverPosition.x = unhoverPosition.x - zoom / 2;
	hoverPosition.y = unhoverPosition.y - zoom / 2;
	hoverSize.x = unhoverSize.x + zoom;
	hoverSize.y = unhoverSize.y + zoom;


	rect.x = unhoverPosition.x;
	rect.y = unhoverPosition.y;
	rect.w = unhoverSize.x;
	rect.h = unhoverSize.y;
}

void Button::CheckIfHovered(Vector2 mousePos)
{
	if (buttonType != clicked)
	{
		if (collider->CheckCollisionOfObjectAndPoint(rect, mousePos))
		{
			buttonType = hovered;
			ChangeHover();
		}
		else
		{
			buttonType = unhovered;
			ChangeHover();
		}
	}
}

void Button::ChangeHover()
{
	if (buttonType == hovered)
	{
		rect.x = hoverPosition.x;
		rect.y = hoverPosition.y;
		rect.w = hoverSize.x;
		rect.h = hoverSize.y;
	}
	else if(buttonType == unhovered)
	{
		rect.x = unhoverPosition.x;
		rect.y = unhoverPosition.y;
		rect.w = unhoverSize.x;
		rect.h = unhoverSize.y;
	}
}

void Button::SetClicked(bool ifClicked)
{
	if (ifClicked)
	{
		if (changeColorWhenClicked)
			buttonType = clicked;
	}
	else
	{
		buttonType = unhovered;
	}
}

void Button::SetNewPosition(Vector2 unhoverPosition)
{
	this->unhoverPosition = unhoverPosition;

	this->unhoverPosition.x -= unhoverSize.x / 2;
	this->unhoverPosition.y -= unhoverSize.y / 2;

	hoverPosition.x = this->unhoverPosition.x - zoom / 2;
	hoverPosition.y = this->unhoverPosition.y - zoom / 2;


	rect.x = this->unhoverPosition.x;
	rect.y = this->unhoverPosition.y;
	rect.w = unhoverSize.x;
	rect.h = unhoverSize.y;
}

void Button::Draw()
{
	DrawShape(outlineColor, GetCurrentPosition().x - outline / 2,GetCurrentPosition().y - outline / 2, GetCurrentSize().x + outline,GetCurrentSize().y + outline);
	DrawShape(GetCurrentColor(), GetCurrentPosition().x, GetCurrentPosition().y, GetCurrentSize().x, GetCurrentSize().y);
	if (buttonText != "")
	{
		int textPosX = GetCurrentPosition().x + GetCurrentSize().x / 2 + outline / 2;
		int textPosY = GetCurrentPosition().y + GetCurrentSize().y / 2 + outline / 2;
		DrawTextForButtons(font, fontColor, buttonText, textPosX, textPosY);
	}
}

SDL_Color Button::GetCurrentColor()
{
	if (buttonType == unhovered)
	{
		return unhoverColor;
	}
	else if (buttonType == hovered)
	{
		return hoverColor;
	}

	if (changeColorWhenClicked)
		return clickColor;

	return unhoverColor;
}

Vector2& Button::GetCurrentPosition()
{
	if (buttonType == unhovered)
	{
		return unhoverPosition;
	}
	else
	{
		return hoverPosition;
	}
}

Vector2& Button::GetCurrentSize()
{
	if (buttonType == unhovered)
	{
		return unhoverSize;
	}
	else
	{
		return hoverSize;
	}
}

bool Button::GetIfClicked(Vector2 mousePos)
{
	if (collider->CheckCollisionOfObjectAndPoint(rect, mousePos))
	{
		SetClicked(true);
		return true;
	}
	return false;
}
