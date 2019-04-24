#include "RawEntity.h"
#include <iostream>

RawEntity::RawEntity(std::vector<float>&& vertices, std::vector<unsigned int>&& indices)
	: m_vertices(std::move(vertices)), m_indices(std::move(indices))
{
	std::cout << "raw entity constructor\n";
}

RawEntity::RawEntity(RawEntity& rawEntity) : m_vertices(rawEntity.getVertices()), m_indices(rawEntity.getIndices())
{
	std::cout << "raw entity copy constructor\n";
}

RawEntity::RawEntity(RawEntity&& rawEntity) : m_vertices(rawEntity.getVertices()), m_indices(rawEntity.getIndices())
{
	std::cout << "raw entity move constructor\n";
}


unsigned int RawEntity::vertexCount()
{
	return m_vertices.size();
}

unsigned int RawEntity::indexCount()
{
	return m_indices.size();
}

std::vector<float>& RawEntity::getVertices()
{
	return m_vertices;
}

std::vector<unsigned int>& RawEntity::getIndices()
{
	return m_indices;
}
