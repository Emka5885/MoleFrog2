#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <cassert>
#include <string>

SDL_Window* GetWindow();
SDL_Renderer* GetRenderer();

void RenderInit();
void RenderTerminate();

void RenderBackground();

void DrawObject(SDL_Texture* texture, int positionX, int positionY, int sizeX, int sizeY);
void DrawShape(SDL_Color color, int positionX, int positionY, int sizeX, int sizeY);
void DrawText(TTF_Font* font, SDL_Color fontColor, SDL_Color fontOutlineColor, std::string text, int x, int y);