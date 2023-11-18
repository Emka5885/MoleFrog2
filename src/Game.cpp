#include "Game.h"
#include <SDL.h>
#include <assert.h>
#include <ctime>
#include <fstream>
#include "Render.h"
#include <iostream>

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
	widgets = new Widgets(assets->GetFont(FONT), "distance (in m): ");
	ground = new Ground({ 0,0,0,255 }, { 0, HEIGHT - 175 }, { WIDTH, 8 });
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
	d = new Data(assets, initialSpeed, 150, 250, 225, 10, HEIGHT - 80);
	data.emplace_back(d);
	d = new Data(assets, gravity, 10, 50, 25, WIDTH / 2 - 100, HEIGHT - 140);
	data.emplace_back(d);
	d = new Data(assets, airDrag, 4, 20, 5, WIDTH / 2 - 100, HEIGHT - 80);
	data.emplace_back(d);

	widgets->SetTextValue("0");

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
			Update(dt);

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
			if (event.button.button == SDL_BUTTON_LEFT && handleInput)
			{
				if (fireButton->GetIfClicked(input->GetMousePosition()))
				{
					cannon->Fire(assets, data);
					handleInput = false;
				}
				mouseButtonClicked = true;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (handleInput)
			{
				mouseButtonClicked = false;
			}
			break;
		}
	}

	if (handleInput)
	{
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
}

void Game::Update(float dt)
{
	if (!handleInput)
	{
		distanceString = std::to_string(cannon->GetBullet()->GetDistanceTraveled());
		distanceText = distanceString.c_str();
		widgets->SetTextValue(distanceText);
		if (!cannon->GetBullet()->GetIfHitGround(ground->GetRect()))
		{
			cannon->GetBullet()->CalculateNewPosition(dt);
		}
		else
		{
			delayNewFire--;
		}
	}

	if (delayNewFire <= 0)
	{
		delayNewFire = 180;
		handleInput = true;
		fireButton->SetClicked(false);
	}
}

void Game::Draw()
{
	RenderBackground();
	ground->Draw();
	widgets->Draw();
	cannon->Draw();
	fireButton->Draw();
	for (int i = 0; i < data.size(); i++)
	{
		data[i]->DrawData();
	}
}
