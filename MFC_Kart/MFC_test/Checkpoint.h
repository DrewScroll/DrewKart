#pragma once

#include "GameObjects.h"

class Checkpoint : public GameObjects
{
public:
	Checkpoint();
	~Checkpoint();
	Checkpoint(Vector2D Pos);

	Checkpoint* m_NextCP;

	void Update();
	void SetNextCP(Checkpoint* NewNextCP);

	/*void SetPosition(Vector2D& Pos);

	In case it won't load automatically
	void SetWorld(World* ActiveWorls)

	Vector2D m_nextCPDirNorm;
	Vector2D m_assistDir;*/
};

