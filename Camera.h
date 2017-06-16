#pragma once
#include "types.h"

class Camera
{
private:
	FixedPointQ8x8 position;
	Angle direction;

	//FixedPointI position;		//To:do later
public:
	void AddPosition(const FixedPointQ8x8 add);
	void SetPosition(const FixedPointQ8x8 position);
	FixedPointQ8x8 GetPosition();

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

void Camera::AddPosition(const FixedPointQ8x8 add)
{
	this->position.X += add.X;
	this->position.Y += add.Y;
}
void Camera::SetPosition(const FixedPointQ8x8 position)
{
	this->position = position;
}

FixedPointQ8x8 Camera::GetPosition()
{
	return position;
}