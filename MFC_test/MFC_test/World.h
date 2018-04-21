#pragma once
#include "GameObjects.h"
#include "Checkpoint.h"
#include "Kart.h"
#include <vector>
class World
{
public:
	World();
	~World();

	std::vector<GameObjects> m_GameObj;
	std::vector <Checkpoint> CheckpointArr;
	std::vector <Kart> KartArr;

	int iTotalCheckpoint = 15;
	int iTotalKarts = 8;
	void Update();
};

