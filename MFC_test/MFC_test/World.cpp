#include "stdafx.h"
#include "World.h"


World::World()
{
	int m_iTotalCheckpoint = 15;
	int m_iTotalKarts = 8;
	
	Vector2D Initial;

	Checkpoint* CP = new Checkpoint(Initial);
	Checkpoint* Next_CP = new Checkpoint(Initial);
	
	m_GameObj.push_back(CP);
	m_GameObj.push_back(Next_CP);

	/*for (int i = 2; i < m_iTotalCheckpoint; i++)
	{
		CP = Next_CP;
		Next_CP = Checkpoint(Initial);
		CP.SetNextCP(&Next_CP);
		m_GameObj.push_back(CP);
		if (i == m_iTotalCheckpoint - 1)
		{
			m_GameObj[i].SetNextCP(&m_CheckpointArr[0]);
		}
	}
	
	for (int i = 0; i < iTotalKarts; i++)
	{
		Kart M(CheckpointArr[0].m_Pos, i + 1, this);
		M.m_Pos.x += i * 5;
		m_GameObj.push_back(M);
	}*/
}


World::~World()
{
}

void World::Update()
{
	for (auto gameObj : m_GameObj)
	{
		gameObj->Update();
	}
}
