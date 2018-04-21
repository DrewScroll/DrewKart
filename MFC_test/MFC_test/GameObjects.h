#pragma once

#include <vector>

struct Vector2D
{
	union
	{
		struct
		{
			float x;
			float y;
		};
		float v[2];
	};
	Vector2D()
	{
		x = 0;
		y = 0;
	}
	Vector2D(float fx, float fy)
	{
		x = fx;
		y = fy;
	}
	Vector2D operator = (Vector2D v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}
	Vector2D operator += (Vector2D v)
	{
		x = x + v.x;
		y = y + v.y;
		return *this;
	}
	Vector2D operator -=(Vector2D v)
	{
		x = x - v.x;
		y = y - v.y;
		return *this;
	}
	Vector2D operator *(float f)
	{
		x = x * f;
		y = y * f;
		return *this;
	}
	Vector2D operator *= (float f)
	{
		x = x * f;
		y = y * f;
		return *this;
	}
	Vector2D operator / (float f)
	{
		x = x / f;
		y = y / f;
		return *this;
	}
	Vector2D operator /= (float f)
	{
		x = x / f;
		y = y / f;
		return *this;
	}
	Vector2D operator - (Vector2D v)
	{
		x = x - v.x;
		y = y - v.y;
		return *this;
	}
	Vector2D operator + (Vector2D v)
	{
		x = x + v.x;
		y = y + v.y;
		return *this;
	}
	float Magnitud()
	{
		return sqrt((x*x) + (y*y));
	}
	void Normalize()
	{
		float mag = Magnitud();
		x *= mag;
		y *= mag;
	}
	Vector2D Direction()
	{
		Vector2D Dir = *this;
		Dir.Normalize();
		return Dir;
	}
	float Distance(Vector2D v)
	{
		return (v - *this).Magnitud();
	}
};

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

