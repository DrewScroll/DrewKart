#include "stdafx.h"
#include "Boid.h"


Boid::Boid()
{
}


Boid::~Boid()
{
}

void Boid::Seek(Vector2D Target, Vector2D output, float fScale)
{
	Vector2D Direction = Target - m_Pos;
	output = Direction.Normalize()*fScale;
	m_Pos += output;
}

void Boid::Flee(Vector2D Target, Vector2D output, float fScale)
{
}

void Boid::Arrive(Vector2D Target, Vector2D output, float fScale)
{
}

void Boid::Wander(Vector2D Target, Vector2D output, float fScale)
{
}

void Boid::Follow_Path(Vector2D Target, Vector2D output, float fScale)
{
}

