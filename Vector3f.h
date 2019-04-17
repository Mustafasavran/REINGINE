#pragma once

class Vector3f
{
public:
	Vector3f(float x, float y, float z) : x(x), y(y), z(z) { }
	void increasePosition(float dx, float dy, float dz) { x += dx; y += dy; z += dz; }
	float x, y, z;
};