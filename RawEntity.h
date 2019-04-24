#pragma once
#include <vector>


class RawEntity
{
public:
	RawEntity(std::vector<float>&& vertices, std::vector<unsigned int>&& indices);
	RawEntity(RawEntity& rawEntity);
	RawEntity(RawEntity&& rawEntity);

	unsigned int vertexCount();
	unsigned int indexCount();

	std::vector<float>& getVertices();
	std::vector<unsigned int>& getIndices();

private:
	std::vector<float> m_vertices;
	std::vector<unsigned int> m_indices;

};
