#pragma once
#include <vector>


class RawEntity
{
public:
	RawEntity(std::vector<float>&& vertices, std::vector<unsigned int>&& indices);
	~RawEntity();

	unsigned int vertexCount();
	unsigned int indexCount();
	unsigned int getVaoID();

private:
	void init(std::vector<float>& vertices, std::vector<unsigned int>& indices);
	void init2(std::vector<float>& vertices, std::vector<unsigned int>& indices);
	std::vector<float> m_vertices;
	std::vector<unsigned int> m_indices;
	unsigned int m_vaoID;
	std::vector<unsigned int> m_vboList;

};
