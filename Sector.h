#pragma once

#include <Arduboy2.h>

#include "Ardutils.h"

#include "Types.h"
#include "Portal.h"
#include "Camera.h"

class Sector
{
public:
	PointI points[8];
	uint8_t pointCount;
	
	Portal portals[4];
	uint8_t portalCount;

public:
	Sector(void) : points(), pointCount(0), portals(), portalCount(0) {}
	
	const PointI & GetPoint(const uint8_t & index) const;
	
	uint8_t GetPointCount(void) const;
	
	const Portal & GetPortal(const uint8_t & index) const;
	
	uint8_t GetPortalCount(void) const;
	
	void Draw2D(Camera & camera,System & arduboy);
};
	
const PointI & Sector::GetPoint(const uint8_t & index) const
{
	return this->points[index];
}
	
uint8_t Sector::GetPointCount(void) const
{
	return this->pointCount;
}
	
const Portal & Sector::GetPortal(const uint8_t & index) const
{
	return this->portals[index];
}
	
uint8_t Sector::GetPortalCount(void) const
{
	return this->portalCount;
}

void Sector::Draw2D(Camera & camera,System & arduboy)
{
	PointI cameraPosition = camera.GetPosition();		//Middle of screen
	int8_t cameraDirection = camera.GetDirection().GetInteger();
	PointI screenCentre = PointI(arduboy.width()/2,arduboy.height()/2);

	FixedPointQ8x8 pointsTransformed[this->pointCount];

	for(uint8_t i=0; i < this->pointCount; ++i)
	{
		pointsTransformed[i] = this->points[i];

		//Translate to camera position
		pointsTransformed[i].X = pointsTransformed[i].X - cameraPosition.X;
		pointsTransformed[i].Y = pointsTransformed[i].Y - cameraPosition.Y;

		//Rotate by camera angle	Not sure why it doesn't work!
		if(cameraDirection != 0)
		{
			pointsTransformed[i].X = (pointsTransformed[i].X*sin(cameraDirection)) - (pointsTransformed[i].Y * cos(cameraDirection));
			pointsTransformed[i].Y = (pointsTransformed[i].X*cos(cameraDirection)) - (pointsTransformed[i].Y * sin(cameraDirection));
		}

		//Translate around screen centre.
		pointsTransformed[i].X += screenCentre.X;
		pointsTransformed[i].Y += screenCentre.Y;
	}

	for(uint8_t i = 0, j = 1; i < this->pointCount; ++i, ++j)
	{
	    if(j == this->pointCount) j = 0;

		arduboy.drawLine(pointsTransformed[i].X.GetInteger(), pointsTransformed[i].Y.GetInteger(), pointsTransformed[j].X.GetInteger(), pointsTransformed[j].Y.GetInteger());
	}
}
