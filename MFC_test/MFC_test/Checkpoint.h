#pragma once

#include "GameObjects.h"

class Checkpoint : public GameObjects
{
public:
	Checkpoint();
	~Checkpoint();
	Checkpoint(Vector2D Pos);
	void Update();


	/* In case it won't load automatically
	void SetWorld(World* ActiveWorls)

	Vector2D m_nextCPDirNorm;
	Vector2D m_assistDir;*/
};

