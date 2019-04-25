#pragma once

class Vector3f
{
public:
	Vector3f(float x, float y, float z) : x(x), y(y), z(z) { }
	Vector3f(const Vector3f& vec) : x(vec.x), y(vec.y), z(vec.z) { }
	void increasePosition(float dx, float dy, float dz) { x += dx; y += dy; z += dz; }
	float x, y, z;
};