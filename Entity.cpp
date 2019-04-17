#include "Entity.h"
#include <GLAD\glad.h>


Entity::Entity(float vertices[], unsigned int vertexCount, unsigned int indices[], unsigned int indexCount)
	:	m_vaoID(0), m_vboList { }, m_vertexCount(vertexCount), m_indexCount(indexCount)
{
	init(vertices, vertexCount, indices, indexCount);
}

Entity::~Entity()
{
	glDeleteVertexArrays(1, &m_vaoID);
	for (unsigned int vboID : m_vboList)
	{
		glDeleteBuffers(1, &vboID);
	}
}

void Entity::init(float vertices[], unsigned int vertexCount, unsigned int indices[], unsigned int indexCount)
{
	glGenVertexArrays(1, &m_vaoID);
	glBindVertexArray(m_vaoID);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

	m_vboList.push_back(VBO);
	m_vboList.push_back(EBO);
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