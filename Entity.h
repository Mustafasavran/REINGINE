#pragma once
#include <vector>
#include "RawEntity.h"
#include "Vector3f.h"

class Entity
{
public:
	Entity(RawEntity& rawEntity, Vector3f worldTranslation, Vector3f worldRotation, float worldScale);
	~Entity();
	unsigned int getVaoID();
	void increaseTranslationVector(float dx, float dy, float dz);
	void increaseRotationVector(float dx, float dy, float dz);
	void increaseScale(float ds);
	Vector3f getTranslationVector();
	Vector3f getRotationVector();
	float getScale();
	unsigned int getIndexCount();
	unsigned int getVertexCount();

private:
	RawEntity& rawEntity;
	void init(std::vector<float>& vertices, std::vector<unsigned int>& indices);
	void init2(std::vector<float>& vertices, std::vector<unsigned int>& indices);
	unsigned int m_vaoID;
	std::vector<unsigned int> m_vboList;
	Vector3f m_translationVector;
	Vector3f m_rotationVector;
	float m_scale;
};