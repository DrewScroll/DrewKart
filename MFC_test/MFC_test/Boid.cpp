#include "stdafx.h"
#include "Boid.h"


Boid::Boid()
{
}


Boid::~Boid()
{
}

Vector2D Boid::Seek(const Vector2D& Target, float fScale)
{
	Vector2D Direction = Target - m_Pos;
	Direction.Normalize();
	return Direction * fScale;
}

Vector2D Boid::Flee(const Vector2D& Target, float fScale)
{
	return Vector2D();
}

Vector2D Boid::Arrive(const Vector2D& Target, float fScale)
{
	return Vector2D();
}

Vector2D Boid::Wander(const Vector2D& Target, float fScale)
{
	return Vector2D();
}

Vector2D Boid::Follow_Path(const Vector2D& Target, float fScale)
{
	return Vector2D();
}

Vector2D Boid::Obs_Avoid(float radius, float fScale)
{
	Vector2D Direction;
	for (auto gameObj : g_MainWorld.m_GameObj)
	{
		Kart* pK = nullptr;
		pK = dynamic_cast<Kart*>(gameObj);
		if (pK == this || pK == nullptr)
			continue;
		if ((pK->m_Pos - m_Pos).Magnitud() < radius)
		{
			Direction += (m_Pos - pK->m_Pos);
		}
	}
	return Direction * fScale;
}

