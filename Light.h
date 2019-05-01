#pragma once
#include "Vector3f.h"

class Light
{
public:
	Light(Vector3f positionVec, Vector3f ambientColor, Vector3f diffuseColor, Vector3f specularColor);

	Vector3f getPositionVec();
	Vector3f getAmbientColor();
	Vector3f getDiffuseColor();
	Vector3f getSpecularColor();

private:
	Vector3f m_positionVec;
	Vector3f m_ambientColor;
	Vector3f m_diffuseColor;
	Vector3f m_specularColor;
};