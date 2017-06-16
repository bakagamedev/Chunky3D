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
	
	void Draw(Camera & camera,System & arduboy);
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

void Sector::Draw(Camera & camera,System & arduboy)
{
	FixedPointQ8x8 cameraPosition = camera.GetPosition();		//Middle of screen
	float cameraDirection = static_cast<float>(camera.GetDirection());//.GetInteger() + (camera.GetFraction() / 256);
	//int8_t cameraDirection = camera.GetDirection().GetInteger();
	PointI screenCentre = PointI(arduboy.width()/2,arduboy.height()/2);

	//FixedPointQ8x8 pointsTransformed[this->pointCount];
	PointF pointsTransformed[this->pointCount];

	for(uint8_t i=0; i < this->pointCount; ++i)
	{
		PointF pointTemp = this->points[i];

		//Translate to camera position
		pointTemp = PointF(pointTemp.X - cameraPosition.X, pointTemp.Y - cameraPosition.Y);

		//Rotate around camera
		pointsTransformed[i].X = (pointTemp.X*sin(cameraDirection)) - (pointTemp.Y * cos(cameraDirection));
		pointsTransformed[i].Y = (pointTemp.X*cos(cameraDirection)) + (pointTemp.Y * sin(cameraDirection));
	}

	for(uint8_t i = 0, j = 1; i < this->pointCount; ++i, ++j)
	{
	    if(j == this->pointCount) j = 0;

	    bool ok = true;
	    if ((pointsTransformed[i].Y > 0) or (pointsTransformed[j].Y > 0))
	    	ok = false;

	    if(ok)
	    {
	    	PointF pointTempI, pointTempJ;

	    	//Stretch X coordinate horizontally on inverse of distance (FOV)
	    	const int16_t FOV = 64;
  
	    	pointTempI.X = pointsTransformed[i].X * (FOV / pointsTransformed[i].Y);
		    pointTempJ.X = pointsTransformed[j].X * (FOV / pointsTransformed[j].Y);

		    //And vertically, for height;
		    const int16_t Height = 32;

		    pointTempI.Y = Height / pointsTransformed[i].Y;
		    pointTempJ.Y = Height / pointsTransformed[j].Y;

		    //top
		    arduboy.drawLine(screenCentre.X+pointTempI.X, screenCentre.Y - pointTempI.Y, screenCentre.X+pointTempJ.X, screenCentre.Y - pointTempJ.Y);
		    //bottom
		    arduboy.drawLine(screenCentre.X+pointTempI.X, screenCentre.Y + pointTempI.Y, screenCentre.X+pointTempJ.X, screenCentre.Y + pointTempJ.Y);
		    //left
		    arduboy.drawLine(screenCentre.X+pointTempI.X, screenCentre.Y - pointTempI.Y, screenCentre.X+pointTempI.X, screenCentre.Y + pointTempI.Y);
		    //right
		    arduboy.drawLine(screenCentre.X+pointTempJ.X, screenCentre.Y - pointTempJ.Y, screenCentre.X+pointTempJ.X, screenCentre.Y + pointTempJ.Y);
		}
	}

	arduboy.drawPixel(screenCentre.X,screenCentre.Y);
}


void Sector::Draw2D(Camera & camera,System & arduboy)
{
	FixedPointQ8x8 cameraPosition = camera.GetPosition();		//Middle of screen
	float cameraDirection = static_cast<float>(camera.GetDirection());//.GetInteger() + (camera.GetFraction() / 256);
	//int8_t cameraDirection = camera.GetDirection().GetInteger();
	PointI screenCentre = PointI(arduboy.width()/2,arduboy.height()/2);

	//FixedPointQ8x8 pointsTransformed[this->pointCount];
	PointF pointsTransformed[this->pointCount];

	for(uint8_t i=0; i < this->pointCount; ++i)
	{
		PointF pointTemp = this->points[i];

		//Translate to camera position
		pointTemp = PointF(pointTemp.X - cameraPosition.X, pointTemp.Y - cameraPosition.Y);

		//Rotate around camera
		//pointsTransformed[i].X = (pointTemp.X*cos(cameraDirection)) - (pointTemp.Y * sin(cameraDirection));
		//pointsTransformed[i].Y = (pointTemp.X*sin(cameraDirection)) + (pointTemp.Y * cos(cameraDirection));
		pointsTransformed[i] = pointTemp;

		//Translate back to screen centre.
		pointsTransformed[i].X += screenCentre.X;
		pointsTransformed[i].Y += screenCentre.Y;
	}

	for(uint8_t i = 0, j = 1; i < this->pointCount; ++i, ++j)
	{
	    if(j == this->pointCount) j = 0;

		//arduboy.drawLine(pointsTransformed[i].X.GetInteger(), pointsTransformed[i].Y.GetInteger(), pointsTransformed[j].X.GetInteger(), pointsTransformed[j].Y.GetInteger());
		arduboy.drawLine(pointsTransformed[i].X, pointsTransformed[i].Y, pointsTransformed[j].X, pointsTransformed[j].Y);
	}
}
