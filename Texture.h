#pragma once
#include <string>

class Texture
{
public:
	Texture(std::string texturePath, unsigned int textureUnit);
	~Texture();

private:
	void init(std::string& texturePath, unsigned int textureUnit);
	unsigned int m_textureID;
};