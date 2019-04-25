#include "Camera.h"

Camera::Camera(Vector3f positionVec, Vector3f frontVec, Vector3f upVec)
	:	m_positionVec(positionVec), m_frontVec(frontVec), m_upVec(upVec)
{
}

Vector3f Camera::getPositionVec()
{
	return m_positionVec;
}

Vector3f Camera::getFrontVec()
{
	return m_frontVec;
}

Vector3f Camera::getUpVec()
{
	return m_upVec;
}
