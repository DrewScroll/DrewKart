#include "stdafx.h"
#include "Vector2D.h"


Vector2D::Vector2D()
{
	x = 0;
	y = 0;
}

Vector2D::~Vector2D()
{
}

Vector2D::Vector2D(const Vector2D & v)
{
	x = v.x;
	y = v.y;
}

float Vector2D::Magnitud()
{
	return sqrt((x*x) + (y*y));
}

Vector2D Vector2D::Normalize()
{
	Vector2D Res;
	float mag = Magnitud();
	if (mag == 0)
	{
		return Res;
	}
	Res.x = x / mag;
	Res.y = y / mag;
	return Res;
}

Vector2D Vector2D::Direction()
{
	Vector2D Dir = *this;
	Dir.Normalize();
	return Dir;
}

Vector2D::Vector2D(float fx, float fy)
{
	x = fx;
	y = fy;
}

Vector2D & Vector2D::operator=(const Vector2D& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

Vector2D & Vector2D::operator+=(const Vector2D & v)
{
	x = x + v.x;
	y = y + v.y;
	return *this;
}

Vector2D & Vector2D::operator-=(const Vector2D& v)
{
	x = x - v.x;
	y = y - v.y;
	return *this;
}

Vector2D Vector2D::operator*(float f) const
{
	Vector2D Res;
	Res.x = x * f;
	Res.y = y * f;
	return Res;
}

Vector2D & Vector2D::operator*=(float f)
{
	x = x * f;
	y = y * f;
	return *this;
}

Vector2D Vector2D::operator/(float f) const
{
	Vector2D Res;
	Res.x = x / f;
	Res.y = y / f;
	return Res;
}

Vector2D & Vector2D::operator/=(float f)
{
	x = x / f;
	y = y / f;
	return *this;
}

Vector2D Vector2D::operator-(const Vector2D& v) const
{
	Vector2D Res;
	Res.x = x - v.x;
	Res.y = y - v.y;
	return Res;
}

Vector2D Vector2D::operator+(const Vector2D& v) const
{
	Vector2D Res;
	Res.x = x + v.x;
	Res.y = y + v.y;
	return Res;
}
