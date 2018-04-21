#include "stdafx.h"
#include "Checkpoint.h"


Checkpoint::Checkpoint()
{
	m_nextCP = nullptr;
}


Checkpoint::~Checkpoint()
{
}

Checkpoint::Checkpoint(Vector2D Pos)
{
	m_Pos = Pos;
	m_nextCP = nullptr;
}

void Checkpoint::Update()
{
}

void Checkpoint::SetNextCP(Checkpoint * NextCP)
{
	m_nextCP = NextCP;
}
