#pragma once
#include "types.h"

class Camera
{
private:
	PointI position;
	Angle direction;

	//FixedPointI position;		//To:do later
public:
	void AddPosition(const PointI add);
	void SetPosition(const PointI position);
	PointI GetPosition();

	void AddDirection(Angle add);
	void SetDirection(Angle angle);
	Angle GetDirection();
};

void Camera::AddDirection(Angle add)
{
	this->direction += add;
}
void Camera::SetDirection(Angle direction)
{
	this->direction = direction;
}
Angle Camera::GetDirection()
{
	return direction;
}

void Camera::AddPosition(const PointI add)
{
	this->position.X += add.X;
	this->position.Y += add.Y;
}
void Camera::SetPosition(const PointI position)
{
	this->position = position;
}

PointI Camera::GetPosition()
{
	return position;
}