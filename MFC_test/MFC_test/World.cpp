#include "stdafx.h"
#include "World.h"


World::World()
{
	int m_iTotalCheckpoint = 15;
	int m_iTotalKarts = 6;
	
	Vector2D Initial;

	/*Checkpoint* CP = new Checkpoint(Initial);
	Checkpoint* Next_CP = new Checkpoint(Initial);
	
	m_GameObj.push_back(CP);
	m_GameObj.push_back(Next_CP);*/

	for (int i = 0; i < m_iTotalCheckpoint; i++)
	{
		Checkpoint* CP = new Checkpoint(Initial);
		m_GameObj.push_back(CP);
		/*if (i == m_iTotalCheckpoint - 1)
		{
		m_GameObj[i].SetNextCP(m_GameObj[0]);

		}*/
	}

	for (int i = 0; i < m_iTotalKarts; i++)
	{
		Kart* M = new Kart(m_GameObj.front()->m_Pos, i + 1, 5);
		M->m_Pos.x += i * 5;
		m_GameObj.push_back(M);
	}
}


World::~World()
{
}

Checkpoint * World::FindCheckPoint(int index)
{
	int icount = 0;
	for (auto gameObj : m_GameObj)
	{
		GameObjects* pObj = gameObj;
		Checkpoint* pCP = nullptr;
		pCP = dynamic_cast<Checkpoint*>(pObj);
		if (pCP == nullptr)
			continue;
		++icount;
		if (icount == index)
			return pCP;
	}
	return nullptr;
}

void World::Update()
{
	for (auto gameObj : m_GameObj)
	{
		gameObj->Update();
	}
}
