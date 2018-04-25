#pragma once
class Vector2D
{
public:
	float x;
	float y;

	Vector2D();	
	~Vector2D();
	Vector2D(float fx, float fy);
	Vector2D(const Vector2D& v);
	float Magnitud();
	Vector2D Normalize();
	Vector2D Direction();

	Vector2D& operator = (const Vector2D& v);
	Vector2D& operator +=(const Vector2D& v);
	Vector2D& operator -=(const Vector2D& v);
	Vector2D operator *(float f) const;
	Vector2D& operator *= (float f);
	Vector2D operator / (float f) const;
	Vector2D& operator /= (float f);
	Vector2D operator - (const Vector2D& v) const;
	Vector2D operator + (const Vector2D& v) const;
};

