#pragma once

class Vector2f
{
public:
	Vector2f(float x, float y) : x(x), y(y) { }
	void increasePosition(float dx, float dy) { x += dx; y += dy; }
	float x, y;
};