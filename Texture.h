#pragma once
#include <string>

class Texture
{
public:
	Texture(std::string texturePath, unsigned int textureUnit);
	~Texture();
	unsigned int getTextureUnit();
	unsigned int getTextureID();

private:
	void init(std::string& texturePath, unsigned int textureUnit);
	unsigned int m_textureID;
	unsigned int m_textureUnit;
};