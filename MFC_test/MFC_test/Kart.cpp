#include "stdafx.h"
#include "Kart.h"


Kart::Kart(const Vector2D& Position, float fMass, float fMaxSpeed)
{
	m_Pos = Position;
	m_Mass = 1/fMass;
	m_MaxSpeed = fMaxSpeed;
	m_currentSpeed = 0;
	m_fCPcount = 0;
	m_CurrentCP = g_MainWorld.FindCheckPoint(m_fCPcount);
	m_MaxCarSize = 2;
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
	m_Steering += Seek(m_CurrentCP->m_Pos, 0.5f);
	m_Pos += (m_Direction + (m_Steering*m_Mass));
	m_Speed = (m_Direction + m_Steering).Normalize()*m_MaxSpeed;

	SetNextCP(g_MainWorld.FindCheckPoint(m_fCPcount));

	if ((m_CurrentCP->m_Pos - m_Pos).Magnitud() < 5)
	{
		++m_fCPcount;
	}
	
	m_Direction = Obs_Avoid(m_MaxCarSize, 300);

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
