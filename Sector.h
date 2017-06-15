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
	PointI cameraPosition = camera.GetPosition();		
	PointI screenCentre = PointI(arduboy.width()/2,arduboy.height()/2);	//Middle of screen
	
	float cameraDirection = static_cast<float>(camera.GetDirection());	//Fix (hahahaha) point this
	//int8_t cameraDirection = camera.GetDirection().GetInteger();

	//FixedPointQ8x8 pointsTransformed[this->pointCount];
	FixedPointQ8x8 pointsTransformed[this->pointCount];

	for(uint8_t i=0; i < this->pointCount; ++i)
	{
		FloatI pointTemp = this->points[i];

		//Translate to camera position
		pointTemp = FixedPointQ8x8(pointTemp.X - cameraPosition.X,pointTemp.Y = pointTemp.Y - cameraPosition.Y);

		//Rotate around camera
		pointsTransformed[i].X = (pointTemp.X*cos(cameraDirection)) - (pointTemp.Y * sin(cameraDirection));
		pointsTransformed[i].Y = (pointTemp.X*sin(cameraDirection)) + (pointTemp.Y * cos(cameraDirection));

		//Translate back to screen centre.
		pointsTransformed[i] = FixedPointQ8x8(pointsTransformed[i].X + screenCentre.X, pointsTransformed[i].Y + screenCentre.Y);
	}

	for(uint8_t i = 0, j = 1; i < this->pointCount; ++i, ++j)
	{
	    if(j == this->pointCount) j = 0;

		arduboy.drawLine(pointsTransformed[i].X.GetInteger(), pointsTransformed[i].Y.GetInteger(), pointsTransformed[j].X.GetInteger(), pointsTransformed[j].Y.GetInteger());
		//arduboy.drawLine(pointsTransformed[i].X, pointsTransformed[i].Y, pointsTransformed[j].X, pointsTransformed[j].Y);
	}

	arduboy.drawPixel(screenCentre.X,screenCentre.Y);
}
