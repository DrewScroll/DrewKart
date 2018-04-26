#include "stdafx.h"
#include "World.h"

World* World::m_Instance = nullptr;

World::World()
{
}

void World::Init()
{
	m_iTotalCheckpoint = 5;
	m_iTotalKarts = 2;

	Vector2D Initial;

	Checkpoint* CP = new Checkpoint(Initial);
	Checkpoint* Next_CP = new Checkpoint(Initial);

	CP->SetNextCP(Next_CP);
	m_GameObj.push_back(CP);
	//m_GameObj.push_back(Next_CP);

	for (int i = 1; i < m_iTotalCheckpoint; i++)
	{
		CP = Next_CP;
		Next_CP = new Checkpoint(Initial);
		CP->SetNextCP(Next_CP);
		m_GameObj.push_back(CP);
		if (i == m_iTotalCheckpoint - 1)
		{
			Checkpoint* pStartCP = nullptr;
			int icount = 0;
			for (auto gameObj : m_GameObj)
			{
				Checkpoint* pCP = nullptr;
				pCP = dynamic_cast<Checkpoint*>(gameObj);
				if (icount == 0)
				{
					pStartCP = dynamic_cast<Checkpoint*>(gameObj);
				}
				else if (icount == i && pCP != nullptr)
				{
					pCP->SetNextCP(pStartCP);
				}
				if (pCP != nullptr)
					++icount;
			}
		}
	}

	int icount = 0;
	for (auto gameObj : m_GameObj)
	{
		if (icount == 0)
		{
			gameObj->m_Pos.x = 200;
			gameObj->m_Pos.y = 100;
		}
		else if (icount == 1)
		{
			gameObj->m_Pos.x = 100;
			gameObj->m_Pos.y = 400;
		}
		else if (icount == 2)
		{
			gameObj->m_Pos.x = 350;
			gameObj->m_Pos.y = 200;
		}
		else if (icount == 3)
		{
			gameObj->m_Pos.x = 50;
			gameObj->m_Pos.y = 200;
		}
		else if (icount == 4)
		{
			gameObj->m_Pos.x = 300;
			gameObj->m_Pos.y = 400;
		}
		/*else if (icount == 5)
		{
			gameObj->m_Pos.x = 200;
			gameObj->m_Pos.y = 300;
		}*/
		++icount;
	}

	for (int i = 0; i < m_iTotalKarts; i++)
	{
		Kart* M = new Kart(m_GameObj.front()->m_Pos, 15, 5);
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
		if (icount == index)
			return pCP;
		else if (icount >= index)
		{

		}
		++icount;
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
