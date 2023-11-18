#include "Render.h"
#include "Definitions.h"

SDL_Window* GetWindow()
{
	// Window has to be stored somewhere becouse we have to destroy it at the end
	static SDL_Window* window;

	if (!window)
	{
		window = SDL_CreateWindow("MoleFrog2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		assert(window != nullptr && "Window could not be created!");

		SDL_Surface* surf = IMG_Load(ICON_PATH);
		SDL_SetWindowIcon(GetWindow(), surf);
	}

	return window;
}

SDL_Renderer* GetRenderer()
{
	static SDL_Renderer* renderer;

	if (!renderer)
	{
		renderer = SDL_CreateRenderer(GetWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		assert(renderer != nullptr && "Renderer could not be created!");
	}

	return renderer;
}

void RenderInit()
{
	GetWindow();
	GetRenderer();
}

void RenderTerminate()
{
	SDL_DestroyRenderer(GetRenderer());
	SDL_DestroyWindow(GetWindow());
}

void RenderBackground()
{
	SDL_SetRenderDrawColor(GetRenderer(), 255, 255, 255, 255);
	SDL_RenderPresent(GetRenderer());
	SDL_RenderClear(GetRenderer());
}

void DrawObject(SDL_Texture* texture, int positionX, int positionY, int sizeX, int sizeY)
{
	SDL_Rect dsrect = { positionX, positionY, sizeX, sizeY };
	assert(texture != nullptr && "Could not draw object, texture invalid!");
	SDL_RenderCopy(GetRenderer(), texture, NULL, &dsrect);
}

void DrawCannon(SDL_Texture* texture, int positionX, int positionY, int sizeX, int sizeY, int ang, SDL_Point& center)
{
	SDL_Rect srcRect = { 0, 0, 44, 31 };
	SDL_Rect dsRect = { positionX, positionY, sizeX, sizeY };
	assert(texture != nullptr && "Could not draw object, texture invalid!");
	SDL_RenderCopyEx(GetRenderer(), texture, &srcRect, &dsRect, ang, &center, SDL_FLIP_NONE);
}

void DrawShape(SDL_Color color, int positionX, int positionY, int sizeX, int sizeY)
{
	SDL_Rect rect = { positionX, positionY, sizeX, sizeY };
	SDL_SetRenderDrawColor(GetRenderer(), color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(GetRenderer(), &rect);
}

void DrawText(TTF_Font* font, SDL_Color fontColor, const char* text, int x, int y)
{
	SDL_Surface* surf;
	SDL_Texture* tex;
	SDL_Rect rect;

	surf = TTF_RenderText_Solid(font, text, fontColor);
	tex = SDL_CreateTextureFromSurface(GetRenderer(), surf);
	rect.x = x;
	rect.y = y;
	rect.w = surf->w;
	rect.h = surf->h;
	SDL_RenderCopy(GetRenderer(), tex, NULL, &rect);

	SDL_FreeSurface(surf);
	SDL_DestroyTexture(tex);
}

void DrawText(TTF_Font* font, SDL_Color fontColor, const char* text, int x, int y, int& textWidth)
{
	SDL_Surface* surf;
	SDL_Texture* tex;
	SDL_Rect rect;

	surf = TTF_RenderText_Solid(font, text, fontColor);
	tex = SDL_CreateTextureFromSurface(GetRenderer(), surf);
	rect.x = x;
	rect.y = y;
	rect.w = surf->w;
	rect.h = surf->h;
	SDL_RenderCopy(GetRenderer(), tex, NULL, &rect);

	textWidth = surf->w;

	SDL_FreeSurface(surf);
	SDL_DestroyTexture(tex);
}

void DrawTextForButtons(TTF_Font* font, SDL_Color fontColor, const char* text, int x, int y)
{
	SDL_Surface* surf;
	SDL_Texture* tex;
	SDL_Rect rect;

	surf = TTF_RenderText_Solid(font, text, fontColor);
	tex = SDL_CreateTextureFromSurface(GetRenderer(), surf);
	rect.x = x - surf->w / 2;
	rect.y = y - surf->h / 2;
	rect.w = surf->w;
	rect.h = surf->h;
	SDL_RenderCopy(GetRenderer(), tex, NULL, &rect);

	SDL_FreeSurface(surf);
	SDL_DestroyTexture(tex);
}
