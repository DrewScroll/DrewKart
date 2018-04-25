#pragma once

#include <vector>
#include "Vector2D.h"

class Checkpoint;

class GameObjects
{
public:
	GameObjects();
	~GameObjects();

	Vector2D m_Pos;
	virtual void Update() = 0;
	virtual void SetNextCP(Checkpoint* NewNextCP) = 0;

};

