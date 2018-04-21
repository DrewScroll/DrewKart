#include "stdafx.h"
#include "Kart.h"


Kart::Kart(Vector2D Position, float fMaxSpeed, World* p_World)
{
	m_Pos = Position;
	MaxSpeed = fMaxSpeed;
	ActiveWorld = p_World;
}


Kart::~Kart()
{
}

void Kart::Update()
{
	currentSpeed = Speed.Magnitud();
	if (currentSpeed > MaxSpeed)
	{
		Speed.Normalize();
		Speed*MaxSpeed;
	}
	else
	{
		Speed.Normalize();
		Speed*currentSpeed;
	}
	Seek(CurrentCP->m_Pos, Speed, 0.5f);
	m_Pos += Speed;
	for (int i = 0; i < ActiveWorld->KartArr.size(); i++)
	{
		if ((ActiveWorld->KartArr[i].m_Pos - m_Pos).Magnitud() <= m_KartSize)
		{
			Speed += (ActiveWorld->KartArr[i].m_Pos - m_Pos)*(MaxSpeed*0.5);
		}
	}
}

void Kart::SetNextCP(Checkpoint * NewNextCP)
{
	CurrentCP = NewNextCP;
}
