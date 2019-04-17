#pragma once
#include <vector>
#include "Vector3f.h"

class Entity
{
public:
	Entity(Vector3f worldTranslation, Vector3f worldRotation, float worldScale, std::vector<float>& vertices, std::vector<unsigned int>& indices);
	~Entity();
	unsigned int getVaoID();
	unsigned int getVertexCount();
	unsigned int getIndexCount();
	void increaseTranslationVector(float dx, float dy, float dz);
	void increaseRotationVector(float dx, float dy, float dz);
	void increaseScale(float ds);
	Vector3f getTranslationVector();
	Vector3f getRotationVector();
	float getScale();

private:
	void init(std::vector<float>& vertices, std::vector<unsigned int>& indices);
	unsigned int m_vaoID;
	unsigned int m_vertexCount;
	unsigned int m_indexCount;
	Vector3f m_translationVector;
	Vector3f m_rotationVector;
	float m_scale;
	std::vector<unsigned int> m_vboList;
};