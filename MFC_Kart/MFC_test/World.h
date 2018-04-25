#pragma once
#include "GameObjects.h"
#include "Checkpoint.h"
#include "Kart.h"
#include <list>

class World
{
private:
	World();

	static World* m_Instance;

public:
	~World();

	std::list<GameObjects*> m_GameObj;
	//std::vector <Checkpoint> CheckpointArr;
	//std::vector <Kart> KartArr;
	Checkpoint* FindCheckPoint(int index);

	int m_iTotalCheckpoint;
	int m_iTotalKarts;
	void Update();
	void Init();

	static World* getInstance()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new World();
		}

		return m_Instance;
	}
};

