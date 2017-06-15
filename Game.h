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
	//Move camera around in here
}

void Game::Draw(void)
{
	if(!arduboy->nextFrame())
		return;
	arduboy->pollButtons();

	arduboy->clear();
	map.Draw2D(camera,*arduboy);

	arduboy->display();
}
