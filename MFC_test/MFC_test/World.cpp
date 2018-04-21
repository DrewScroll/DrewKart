#include "stdafx.h"
#include "World.h"


World::World()
{
	Vector2D Initial; 
	Checkpoint CP(Initial);
	Checkpoint Next_CP(Initial);

	CP.SetNextCP(&Next_CP);
	m_GameObj.push_back(CP);
	m_GameObj.push_back(Next_CP);

	for (int i = 2; i < iTotalCheckpoint; i++)
	{
		CP = Next_CP;
		Next_CP = Checkpoint(Initial);
		CP.SetNextCP(&Next_CP);
		m_GameObj.push_back(CP);
		if (i == iTotalCheckpoint - 1)
		{
			m_GameObj[i].SetNextCP(&CheckpointArr[0]);
		}
	}
	
	for (int i = 0; i < iTotalKarts; i++)
	{
		Kart M(CheckpointArr[0].m_Pos, i + 1, this);
		M.m_Pos.x += i * 5;
		m_GameObj.push_back(M);
	}
}


World::~World()
{
}

void World::Update()
{
	for (int i = 0; i < m_GameObj.size(); i++)
	{
		m_GameObj[i].Update();
	}
}
