#pragma once
#include "GameObjects.h"
#include "Checkpoint.h"
#include "Kart.h"
#include <list>

class World
{
public:
	World();
	~World();

	std::list<GameObjects*> m_GameObj;
	//std::vector <Checkpoint> CheckpointArr;
	//std::vector <Kart> KartArr;

	int m_iTotalCheckpoint;
	int m_iTotalKarts;
	void Update();
};

