#pragma once
#include <vector>
#include "RawEntity.h"
#include "Vector3f.h"
#include "Texture.h"

class Entity
{
public:
	Entity(RawEntity& rawEntity, Texture& texture, Vector3f worldTranslation, Vector3f worldRotation, float worldScale);
	unsigned int getVaoID();
	unsigned int getTextureID();
	unsigned int getTextureUnit();
	void increaseTranslationVector(float dx, float dy, float dz);
	void increaseRotationVector(float dx, float dy, float dz);
	void increaseScale(float ds);
	Vector3f getTranslationVector();
	Vector3f getRotationVector();
	float getScale();
	unsigned int getIndexCount();
	unsigned int getVertexCount();

private:
	RawEntity& m_rawEntity;
	Texture& m_texture;
	Vector3f m_translationVector;
	Vector3f m_rotationVector;
	float m_scale;
};