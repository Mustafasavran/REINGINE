#include "RawEntity.h"
#include <GLAD\glad.h>
#include <iostream>

RawEntity::RawEntity(std::vector<float>&& vertices, std::vector<unsigned int>&& indices)
	: m_vertices(std::move(vertices)), m_indices(std::move(indices))
{
	std::cout << "raw entity constructor\n";
	init(m_vertices, m_indices);
}

RawEntity::~RawEntity()
{
	glDeleteVertexArrays(1, &m_vaoID);
	for (unsigned int vboID : m_vboList)
	{
		glDeleteBuffers(1, &vboID);
	}
}

void RawEntity::init(std::vector<float>& vertices, std::vector<unsigned int>& indices)
{
	glGenVertexArrays(1, &m_vaoID);
	glBindVertexArray(m_vaoID);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexCount() * sizeof(float), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	m_vboList.push_back(VBO);
	m_vboList.push_back(EBO);
}


void RawEntity::init2(std::vector<float>& vertices, std::vector<unsigned int>& indices)
{
	glGenVertexArrays(1, &m_vaoID);
	glBindVertexArray(m_vaoID);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexCount() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	m_vboList.push_back(VBO);
	m_vboList.push_back(EBO);
}



unsigned int RawEntity::vertexCount()
{
	return m_vertices.size();
}

unsigned int RawEntity::indexCount()
{
	return m_indices.size();
}

unsigned int RawEntity::getVaoID()
{
	return m_vaoID;
}


