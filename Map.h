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

	float cameraDirection = static_cast<float>(camera.GetDirection());
	PointI screenCentre = PointI(arduboy.width()/2,arduboy.height()/2);
	FixedPointQ8x8 cameraVector = FixedPointQ8x8(cos(cameraDirection)*4, sin(cameraDirection)*4);
	arduboy.drawLine(screenCentre.X, screenCentre.Y, screenCentre.X + cameraVector.X.GetInteger(), screenCentre.Y + cameraVector.Y.GetInteger());
}


void Map::Draw(Camera & camera,System & arduboy)
{
	for(uint8_t i = 0; i < this->sectorCount; ++i)
	{
		sectors[i].Draw(camera,arduboy);
	}
}