#include "Render.h"
#include "Definitions.h"

SDL_Window* GetWindow()
{
	// Window has to be stored somewhere becouse we have to destroy it at the end
	static SDL_Window* window;

	if (!window)
	{
		window = SDL_CreateWindow("MoleFrog", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		assert(window != nullptr && "Window could not be created!");
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
	SDL_SetRenderDrawColor(GetRenderer(), 130, 130, 130, 255);
	SDL_RenderPresent(GetRenderer());
	SDL_RenderClear(GetRenderer());
}

void DrawObject(SDL_Texture* texture, int positionX, int positionY, int sizeX, int sizeY)
{
	SDL_Rect dsrect = { positionX, positionY, sizeX, sizeY };
	assert(texture != nullptr && "Could not draw object, texture invalid!");
	SDL_RenderCopy(GetRenderer(), texture, NULL, &dsrect);
}

void DrawShape(SDL_Color color, int positionX, int positionY, int sizeX, int sizeY)
{
	SDL_Rect rect = { positionX, positionY, sizeX, sizeY };
	SDL_SetRenderDrawColor(GetRenderer(), color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(GetRenderer(), &rect);
}