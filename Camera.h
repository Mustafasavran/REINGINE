#pragma once
#include "Vector3f.h"

class Camera
{
public:
	Camera(Vector3f positionVec, Vector3f frontVec, Vector3f upVec);
	Vector3f getPositionVec();
	Vector3f getFrontVec();
	Vector3f getUpVec();
private:
	Vector3f m_positionVec;
	Vector3f m_frontVec;
	Vector3f m_upVec;
};