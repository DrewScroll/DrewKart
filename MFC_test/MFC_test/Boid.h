#pragma once

#include "GameObjects.h"

class Boid : public GameObjects
{
public:
	Boid();
	~Boid();

	Vector2D Seek(Vector2D Targe, float fScale);
	Vector2D Flee(Vector2D Target, float fScale);
	Vector2D Arrive(Vector2D Target, float fScale);
	Vector2D Wander(Vector2D Target, float fScale);
	Vector2D Follow_Path(Vector2D Target, float fScale);

	virtual void Update() = 0;
};

