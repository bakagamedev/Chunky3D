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
	///Replace with 0.1 once set up with fixed points
	if(arduboy->pressed(UP_BUTTON))
	{
		camera.AddPosition(PointI(0, -1));
		//camera.AddPosition(PointI(1 * cos(camera.GetDirection().GetInteger()), 1 * sin(camera.GetDirection().GetInteger())));
	}
	if(arduboy->pressed(DOWN_BUTTON))
	{
		camera.AddPosition(PointI(0, 1));
		//camera.AddPosition(PointI(-1 * cos(camera.GetDirection().GetInteger()), -1 * sin(camera.GetDirection().GetInteger())));
	}
	if(arduboy->pressed(LEFT_BUTTON))
	{
		camera.AddPosition(PointI(-1, 0));
		//camera.AddDirection(-0.1);
	}
	if(arduboy->pressed(RIGHT_BUTTON))
	{
		camera.AddPosition(PointI(1, 0));
		//camera.AddDirection(0.1);
	}

	if(arduboy->pressed(A_BUTTON))
	{
		camera.AddDirection(0.1);
	}
	if(arduboy->pressed(B_BUTTON))
	{
		camera.AddDirection(-0.1);
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

	arduboy->display();
}
