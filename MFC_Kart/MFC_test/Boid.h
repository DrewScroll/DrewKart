#pragma once

#include "GameObjects.h"

class Boid : public GameObjects
{
public:
	Boid();
	~Boid();

	Vector2D Seek(const Vector2D& Target, float fScale);
	Vector2D Flee(const Vector2D& Target, float fScale);
	Vector2D Arrive(const Vector2D& Target, float fScale);
	Vector2D Wander(const Vector2D& Target, float fScale);
	Vector2D Follow_Path(const Vector2D& Target, float fScale);
	Vector2D Obs_Avoid(float radius, float fScale);

	virtual void Update() = 0;
};

