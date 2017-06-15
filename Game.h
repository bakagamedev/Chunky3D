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
		camera.AddPosition(PointI(camera.GetPosition().X, camera.GetPosition().Y-1));
		//camera.AddPosition(PointI(1 * cos(camera.GetDirection().GetInteger()), 1 * sin(camera.GetDirection().GetInteger())));
	}
	if(arduboy->pressed(DOWN_BUTTON))
	{
		camera.AddPosition(PointI(camera.GetPosition().X, camera.GetPosition().Y+1));
	}
	if(arduboy->pressed(LEFT_BUTTON))
	{
		camera.AddPosition(PointI(camera.GetPosition().X-1, camera.GetPosition().Y));
	}
	if(arduboy->pressed(RIGHT_BUTTON))
	{
		camera.AddPosition(PointI(camera.GetPosition().X+1, camera.GetPosition().Y));
	}
}

void Game::Draw(void)
{
	if(!arduboy->nextFrame())
		return;
	arduboy->pollButtons();

	Tick();

	arduboy->clear();
	map.Draw2D(camera,*arduboy);

	arduboy->display();
}
