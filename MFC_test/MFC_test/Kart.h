#pragma once

#include "Boid.h"
#include "Checkpoint.h"

class Kart : public Boid
{
public:
	Kart(Vector2D Position, float fMaxSpeed);
	~Kart();

	Vector2D m_Direction;
	Vector2D m_Speed;
	float m_KartSize = 2;
	float m_currentSpeed = 0;
	float m_MaxSpeed;
	Checkpoint* m_StartingCP;
	Checkpoint* m_CurrentCP;

	void Update();
	void SetNextCP(Checkpoint* NewNextCP);
};

