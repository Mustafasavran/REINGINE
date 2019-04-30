#include "OBJLoader.h"
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <ostream>
#include "Vertex.h"
#include "Vector3f.h"
#include "Vector2f.h"


namespace
{
	void processVertex(std::vector<unsigned int>& index, std::vector<Vertex>& v, std::vector<Vector2f>& vt, std::vector<Vector3f>& vn, std::vector<unsigned int>& indices);
}

RawEntity OBJLoader::loadFile(std::string path)
{
	std::vector<Vertex> v;
	std::vector<Vector2f> vt;
	std::vector<Vector3f> vn;
	std::vector<unsigned int> indices;

	std::ifstream file(path);
	std::string line;
	std::vector<float> tokenFloatList;
	std::vector<unsigned int> tokenUintList;

	// process v, vt, vn information
	while (std::getline(file, line))
	{
		std::string token;
		std::stringstream tokenizer(line);
		std::string identifier = "";

		if (line.rfind("f ", 0) == 0)
			break;
		else if (!(line.rfind("v ", 0) == 0 || line.rfind("vt ", 0) == 0 || line.rfind("vn ", 0) == 0))
			continue;
		else
			tokenizer >> identifier;

		while (tokenizer >> token)
			tokenFloatList.push_back(std::stof(token));

		if (identifier == "v")
		{
			Vector3f vec3(tokenFloatList[0], tokenFloatList[1], tokenFloatList[2]);
			v.push_back(Vertex(vec3));
		}
		else if (identifier == "vt")
		{
			Vector2f vec2(tokenFloatList[0], tokenFloatList[1]);
			vt.push_back(vec2);
		}
		else if (identifier == "vn")
		{
			Vector3f vec3(tokenFloatList[0], tokenFloatList[1], tokenFloatList[2]);
			vn.push_back(vec3);
		}

		tokenFloatList.clear();
	}

	//process f information
	do {
		std::string token;
		std::stringstream tokenizer(line);

		if (line.rfind("f ", 0) == 0)
			tokenizer.ignore();
		else
			continue;

		while (tokenizer >> token)
		{
			std::stringstream innerTokenizer(token);
			std::string innerToken = "";
			while (std::getline(innerTokenizer, innerToken, '/'))
			{
				tokenUintList.push_back(std::stoul(innerToken));
			}
			processVertex(tokenUintList, v, vt, vn, indices);
			tokenUintList.clear();
		}
	} while (std::getline(file, line));

	// organize v vt vn into a final std::vector
	std::vector<float> finalVertexList;
	for (Vertex& vertex : v)
	{
		Vector3f& vec3Pos = vertex.position;
		Vector2f& vec2Tex = vt.at(vertex.textureIndex);
		Vector3f& vec3Norm = vn.at(vertex.normalIndex);
		//float fArray[] = { vec3Pos.x, vec3Pos.y, vec3Pos.z, vec2Tex.x, vec2Tex.y };
		float fArray[] = { vec3Pos.x, vec3Pos.y, vec3Pos.z, vec2Tex.x, vec2Tex.y, vec3Norm.x, vec3Norm.y, vec3Norm.z };
		for (float f : fArray)
			finalVertexList.push_back(f);
	}

	return RawEntity(std::move(finalVertexList), std::move(indices));
}


namespace
{
	void processVertex(std::vector<unsigned int>& index, std::vector<Vertex>& v, std::vector<Vector2f>& vt, std::vector<Vector3f>& vn, std::vector<unsigned int>& indices)
	{
		unsigned int vertexIndex = index[0] - 1;
		unsigned int textureIndex = index[1] - 1;
		unsigned int normalIndex = index[2] - 1;
		bool flag = false;

		Vertex& vertex = v.at(vertexIndex);
		if (!vertex.isSet())
		{
			vertex.textureIndex = textureIndex;
			vertex.normalIndex = normalIndex;
			indices.push_back(vertexIndex);
			flag = true;
		}
		else if (vertex.textureIndex == textureIndex && vertex.normalIndex == normalIndex)
		{
			indices.push_back(vertexIndex);
			flag = true;
		}
		else
		{
			if (!vertex.duplicateIndices.empty())
			{
				for (unsigned int duplicateIndex : vertex.duplicateIndices)
				{
					Vertex& duplicateVertex = v.at(duplicateIndex);
					if (duplicateVertex.textureIndex == textureIndex && duplicateVertex.normalIndex == normalIndex)
					{
						indices.push_back(duplicateIndex);
						flag = true;
						break;
					}
				}
			}
		}

		if (!flag)
		{
			indices.push_back(v.size());
			vertex.duplicateIndices.push_back(v.size());
			Vertex newVertex = Vertex(vertex.position);
			newVertex.textureIndex = textureIndex;
			newVertex.normalIndex = normalIndex;
			v.push_back(newVertex);
		}
	}
}