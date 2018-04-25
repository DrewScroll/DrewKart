#include "stdafx.h"
#include "Kart.h"
#include "World.h"

Kart::Kart(const Vector2D& Position, float fMass, float fMaxSpeed)
{
	m_Pos = Position;
	m_Mass = 1/fMass;
	m_MaxSpeed = fMaxSpeed;
	m_currentSpeed = 0;
	m_fCPcount = 0;
	m_CurrentCP = World::getInstance()->FindCheckPoint(m_fCPcount);
	m_MaxCarSize = 12;
}

Kart::~Kart()
{
}

void Kart::Update()
{
	Vector2D m_Steering;
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
	m_Steering += ((Seek(m_CurrentCP->m_Pos, 0.5f)).Normalize());
	m_Pos += (m_Direction + (m_Steering*m_Mass));
	m_Speed = ((m_Direction + m_Steering)*m_MaxSpeed).Normalize();
	m_Direction = m_Steering.Normalize();

	SetNextCP(World::getInstance()->FindCheckPoint(m_fCPcount));

	if ((m_CurrentCP->m_Pos - m_Pos).Magnitud() < 5)
	{
		++m_fCPcount;
		if (m_fCPcount >= World::getInstance()->m_iTotalCheckpoint)
		{
			m_fCPcount = 0;
		}
	}
	
	m_Direction += (Obs_Avoid(m_MaxCarSize, 300)).Normalize();

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

//bool Kart::isCollided(const Vector2D & Position)
//{
//	if ((Position-m_Pos).Magnitud() < m_KartSize)
//	{
//		return true;
//	}
//	return false;
//}
