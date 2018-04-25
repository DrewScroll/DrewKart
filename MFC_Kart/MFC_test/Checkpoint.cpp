#include "stdafx.h"
#include "Checkpoint.h"


Checkpoint::Checkpoint()
{
}


Checkpoint::~Checkpoint()
{
}

Checkpoint::Checkpoint(Vector2D Pos)
{
	m_Pos = Pos;
}

void Checkpoint::Update()
{
}

void Checkpoint::SetNextCP(Checkpoint * NewNextCP)
{
	m_NextCP = NewNextCP;
}

//void Checkpoint::SetPosition(Vector2D & Pos)
//{
//	m_Pos = Pos;
//}
