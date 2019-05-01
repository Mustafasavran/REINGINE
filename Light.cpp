#include "Light.h"

Light::Light(Vector3f positionVec, Vector3f ambientColor, Vector3f diffuseColor, Vector3f specularColor)
	: m_positionVec(positionVec), m_ambientColor(ambientColor), m_diffuseColor(diffuseColor), m_specularColor(specularColor)
{
}

Vector3f Light::getPositionVec()
{
	return m_positionVec;
}

Vector3f Light::getAmbientColor()
{
	return m_ambientColor;
}

Vector3f Light::getDiffuseColor()
{
	return m_diffuseColor;
}

Vector3f Light::getSpecularColor()
{
	return m_specularColor;
}
