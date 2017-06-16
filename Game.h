#pragma once

#include "System.h"
#include "Maps.h"
#include "Types.h"
#include "Portal.h"
#include "Sector.h"
#include "Map.h"
#include "PgmLoad.h"
#include "Camera.h"

class Game
{
private:
	System * arduboy;

	Map map;
	Camera camera;
public:
	Game(System & arduboy);

  	void Load(void);

  	void Tick(void);
	void Draw(void);
};

Game::Game(System & arduboy)
{
	this->arduboy = &arduboy;
}

void Game::Load(void)
{
	pgmLoadMap(map, &map1);
}

void Game::Tick(void)
{
	float cameraDirection = static_cast<float>(camera.GetDirection());// * (180 / 3.14);

	if(arduboy->pressed(UP_BUTTON))
	{
		camera.AddPosition(FixedPointQ8x8(+cos(cameraDirection), +sin(cameraDirection)));
	}
	if(arduboy->pressed(DOWN_BUTTON))
	{
		camera.AddPosition(FixedPointQ8x8(-cos(cameraDirection), -sin(cameraDirection)));
	}
	if(arduboy->pressed(LEFT_BUTTON))
	{
		camera.AddPosition(FixedPointQ8x8(-cos(cameraDirection), +sin(cameraDirection)));
	}
	if(arduboy->pressed(RIGHT_BUTTON))
	{
		camera.AddPosition(FixedPointQ8x8(+cos(cameraDirection), -sin(cameraDirection)));
	}

	if(arduboy->pressed(A_BUTTON))
	{
		camera.AddDirection(-0.1);
	}
	if(arduboy->pressed(B_BUTTON))
	{
		camera.AddDirection(+0.1);
	}
}

void Game::Draw(void)
{
	if(!arduboy->nextFrame())
		return;
	arduboy->pollButtons();

	Tick();

	arduboy->clear();

	map.Draw(camera,*arduboy);
	map.Draw2D(camera,*arduboy);

	arduboy->display();
}
