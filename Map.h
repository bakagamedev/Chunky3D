#pragma once
#include <Arduboy2.h>
#include "Ardutils.h"

#include "Sector.h"
#include "Camera.h"

class Map
{
public:
	Sector sectors[16];
	uint8_t sectorCount;
	
public:
	Map(void) : sectors(), sectorCount(0) {}
	
	void Draw2D(Camera & camera,System & arduboy);
	void Draw(Camera & camera,System & arduboy);
};

void Map::Draw2D(Camera & camera,System & arduboy)
{
	for(uint8_t i = 0; i < this->sectorCount; ++i)
	{
		sectors[i].Draw2D(camera,arduboy);
	}
}


void Map::Draw(Camera & camera,System & arduboy)
{
	for(uint8_t i = 0; i < this->sectorCount; ++i)
	{
		sectors[i].Draw(camera,arduboy);
	}
}