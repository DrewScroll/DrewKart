#pragma once
#include "GameObjects.h"
class Boid : public GameObjects
{
public:
	Boid();
	~Boid();

	void Seek(Vector2D Target, Vector2D output, float fScale);
	void Flee(Vector2D Target, Vector2D output, float fScale);
	void Arrive(Vector2D Target, Vector2D output, float fScale);
	void Wander(Vector2D Target, Vector2D output, float fScale);
	void Follow_Path(Vector2D Target, Vector2D output, float fScale);

	virtual void Update() = 0;
};

