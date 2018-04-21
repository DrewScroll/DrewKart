#pragma once
#include "Boid.h"
#include "Checkpoint.h"
class Kart : public Boid
{
public:
	Kart(Vector2D Position, float fMaxSpeed, World* p_World);
	~Kart();

	Vector2D Direction;
	Vector2D Speed;
	float m_KartSize = 2;
	float currentSpeed = 0;
	float MaxSpeed;
	Checkpoint* StartingCP;
	Checkpoint* CurrentCP;

	void Update();
	void SetNextCP(Checkpoint* NewNextCP);
};

