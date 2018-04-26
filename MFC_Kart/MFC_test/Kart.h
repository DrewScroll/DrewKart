#pragma once

#include "Boid.h"
#include "Checkpoint.h"

class Kart : public Boid
{
public:
	Kart(const Vector2D& Position, float fMass, float fMaxSpeed);
	~Kart();

	Vector2D m_Direction;
	//Vector2D m_Speed;
	Vector2D m_Steering;
	float m_Mass;
	float m_MaxCarSize;
	//float m_currentSpeed;
	float m_MaxSpeed;
	float m_fCPcount;
	Checkpoint* m_CurrentCP;

	void Update();
	void SetNextCP(Checkpoint* NewNextCP);
	//bool isCollided(const Vector2D& Position);
};

