#include "stdafx.h"
#include "Boid.h"


Boid::Boid()
{
}


Boid::~Boid()
{
}

Vector2D Boid::Seek(Vector2D Target, float fScale)
{
	Vector2D Direction = Target - m_Pos;
	Direction.Normalize();
	return Direction * fScale;
}

Vector2D Boid::Flee(Vector2D Target, float fScale)
{
	return Vector2D();
}

Vector2D Boid::Arrive(Vector2D Target, float fScale)
{
	return Vector2D();
}

Vector2D Boid::Wander(Vector2D Target, float fScale)
{
	return Vector2D();
}

Vector2D Boid::Follow_Path(Vector2D Target, float fScale)
{
	return Vector2D();
}

