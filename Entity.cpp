#include "Entity.h"
#include <GLAD\glad.h>

Entity::Entity(Vector3f worldTranslation, Vector3f worldRotation, float worldScale, std::vector<float>& vertices, std::vector<unsigned int>& indices)
	: m_translationVector(worldTranslation.x, worldTranslation.y, worldTranslation.z),
	  m_rotationVector(worldRotation.x, worldRotation.y, worldRotation.z), m_scale(worldScale)
{
	m_vertexCount = vertices.size();
	m_indexCount = indices.size();
	init(vertices, indices);
}

Entity::~Entity()
{
	glDeleteVertexArrays(1, &m_vaoID);
	for (unsigned int vboID : m_vboList)
	{
		glDeleteBuffers(1, &vboID);
	}
}

void Entity::init(std::vector<float>& vertices, std::vector<unsigned int>& indices)
{
	glGenVertexArrays(1, &m_vaoID);
	glBindVertexArray(m_vaoID);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexCount * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, m_vertexCount * sizeof(float), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	m_vboList.push_back(VBO);
	m_vboList.push_back(EBO);
}



Vector3f Entity::getTranslationVector()
{
	return m_translationVector;
}

Vector3f Entity::getRotationVector()
{
	return m_rotationVector;
}

float Entity::getScale()
{
	return m_scale;
}

void Entity::increaseTranslationVector(float dx, float dy, float dz)
{
	m_translationVector.increasePosition(dx, dy, dz);
}

void Entity::increaseRotationVector(float dx, float dy, float dz)
{
	m_rotationVector.increasePosition(dx, dy, dz);
}

void Entity::increaseScale(float ds)
{
	m_scale += ds;
}

unsigned int Entity::getVaoID()
{
	return m_vaoID;
}

unsigned int Entity::getIndexCount()
{
	return m_indexCount;
}


unsigned int Entity::getVertexCount()
{
	return m_vertexCount;
}