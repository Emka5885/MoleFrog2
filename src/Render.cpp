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

void DrawShape(SDL_Color color, int positionX, int positionY, int sizeX, int sizeY)
{
	SDL_Rect rect = { positionX, positionY, sizeX, sizeY };
	SDL_SetRenderDrawColor(GetRenderer(), color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(GetRenderer(), &rect);
}

void DrawText(TTF_Font* font, SDL_Color fontColor, SDL_Color fontOutlineColor, std::string text, int x, int y)
{
	char character;
	int textWidth = 0;
	for (int i = text.size() - 1; i >= 0; i--)
	{
		SDL_Surface* surf;
		SDL_Texture* tex;
		SDL_Rect rect;

		character = text[i];
		std::string mark;
		mark += character;
		const char* st = mark.c_str();

		// basic text
		surf = TTF_RenderText_Solid(font, st, fontColor);
		tex = SDL_CreateTextureFromSurface(GetRenderer(), surf);
		rect.x = x - surf->w - textWidth;
		rect.y = y;
		rect.w = surf->w;
		rect.h = surf->h;
		SDL_RenderCopy(GetRenderer(), tex, NULL, &rect);
		textWidth += surf->w + 2;

		SDL_FreeSurface(surf);
		SDL_DestroyTexture(tex);
	}
}
