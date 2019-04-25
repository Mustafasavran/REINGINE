#pragma once
#include "Vector3f.h"
#include <vector>

class Vertex
{
public:
	Vertex(Vector3f position) : position(position), textureIndex(-1), normalIndex(-1) {};
	bool isSet() { return (textureIndex != -1 && normalIndex != -1) ? true : false; }
	std::vector<unsigned int> duplicateIndices;
	int textureIndex;
	int normalIndex;
	Vector3f position;
};