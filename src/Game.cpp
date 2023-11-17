#include "Game.h"
#include <SDL.h>
#include <assert.h>
#include <ctime>
#include <fstream>
#include "Render.h"

Game::Game()
{
	//SDL Init
	int result = SDL_Init(SDL_INIT_VIDEO);
	assert(result == 0 && "SDL could not initialize!");
	//TTF Init
	result = TTF_Init();
	assert(result == 0 && "Font could not initialize!");
	//SDL_Image Init
	int imgFlags = IMG_INIT_PNG;
	int imgInitResult = IMG_Init(imgFlags);
	assert((imgInitResult & imgFlags) == imgFlags && "SDL_Image could not initialize!");

	assets = new AssetManager();
	input = new InputManager();
	cannon = new Cannon(assets->GetTexture(CANNON));
	fireButton = new Button({ 150,75 }, { 255,255,255,255 }, { 0,0,0,255 }, { 255,0,0,255 }, "FIRE!", assets->GetFont(FIRE_FONT), 4, { WIDTH - 200, HEIGHT - 90 }, true);

	Init();
}

Game::~Game()
{
	RenderTerminate();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void Game::Init()
{
	srand(time(NULL));

	Data* d = new Data(assets, angle, 0, 90, 45, 10, HEIGHT - 140);
	data.emplace_back(d);
	d = new Data(assets, initialSpeed, 0, 100, 0, 10, HEIGHT - 80);
	data.emplace_back(d);
	d = new Data(assets, gravity, 0, 10, 10, WIDTH / 2 - 100, HEIGHT - 140);
	data.emplace_back(d);
	d = new Data(assets, airDrag, 0, 10, 1, WIDTH / 2 - 100, HEIGHT - 80);
	data.emplace_back(d);

	RenderInit();
}

void Game::Loop()
{
	float dt = (float)(SDL_GetTicks() / 1000.f);
	float lastTime = 0.f;
	const float DESIRED_DT = 1 / 60.f; // 60 FPS 

	while (!quitt)
	{
		dt = (SDL_GetTicks() - lastTime) / 1000;

		if (dt >= DESIRED_DT)
		{
			Input();
			Update();

			lastTime = (float)SDL_GetTicks();
		}

		Draw();
	}
}

void Game::Input()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			quitt = true;
			break;

		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				quitt = true;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				if (fireButton->GetIfClicked(input->GetMousePosition()))
				{
					cannon->Fire(assets, data);
				}
				mouseButtonClicked = true;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			mouseButtonClicked = false;
			break;
		}
	}

	if (mouseButtonClicked)
	{
		if (delayOfClickedMouseButton <= 0)
		{
			for (int i = 0; i < data.size(); i++)
			{
				data[i]->CheckToSetNewValue(input->GetMousePosition());
			}

			delayOfClickedMouseButton = 3;
		}
		else
		{
			delayOfClickedMouseButton--;
		}
	}

	fireButton->CheckIfHovered(input->GetMousePosition());
	for (int i = 0; i < data.size(); i++)
	{
		data[i]->CheckIfButtonsHover(input->GetMousePosition());
	}
}

void Game::Update()
{
}

void Game::Draw()
{
	RenderBackground();
	DrawShape({ 0,0,0,255 }, 0, HEIGHT - 175, WIDTH, 8);
	cannon->Draw();
	fireButton->Draw();
	for (int i = 0; i < data.size(); i++)
	{
		data[i]->DrawData();
	}
}
