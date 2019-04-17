#pragma once
#include <vector>

class Entity
{
public:
	Entity(float vertices[], unsigned int vertexCount, unsigned int indices[], unsigned int indexCount);
	~Entity();
	unsigned int getVaoID();
	unsigned int getVertexCount();
	unsigned int getIndexCount();

private:
	void init(float vertices[], unsigned int vertexCount, unsigned int indices[], unsigned int indexCount);
	unsigned int m_vaoID;
	unsigned int m_vertexCount;
	unsigned int m_indexCount;
	std::vector<unsigned int> m_vboList;
};