#include "stdafx.h"
#include "Kart.h"


Kart::Kart(Vector2D Position, float fMaxSpeed)
{
	m_Pos = Position;
	m_MaxSpeed = fMaxSpeed;
}


Kart::~Kart()
{
}

void Kart::Update()
{
	m_currentSpeed = m_Speed.Magnitud();
	if (m_currentSpeed > m_MaxSpeed)
	{
		m_Speed.Normalize();
		m_Speed*m_MaxSpeed;
	}
	else
	{
		m_Speed.Normalize();
		m_Speed*m_currentSpeed;
	}
	Seek(m_CurrentCP->m_Pos, 0.5f);
	m_Pos += m_Speed;
	/*for (int i = 0; i < ActiveWorld->KartArr.size(); i++)
	{
		if ((ActiveWorld->KartArr[i].m_Pos - m_Pos).Magnitud() <= m_KartSize)
		{
			m_Speed += (ActiveWorld->KartArr[i].m_Pos - m_Pos)*(m_MaxSpeed*0.5);
		}
	}*/
}

void Kart::SetNextCP(Checkpoint * NewNextCP)
{
	m_CurrentCP = NewNextCP;
}
