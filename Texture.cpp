#define STB_IMAGE_IMPLEMENTATION
#include <STB\stb_image.h>
#include <iostream>

#include "Texture.h"
#include <GLAD\glad.h>

Texture::Texture(std::string texturePath, unsigned int textureUnit)
	: m_textureID{ 0 }
{
	init(texturePath, textureUnit);
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_textureID);
}

void Texture::init(std::string& texturePath, unsigned int textureUnit)
{
	glGenTextures(1, &m_textureID);
	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_2D, m_textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	
	unsigned char *data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		unsigned int bitDepth;
		if (nrChannels == 3)
			bitDepth = GL_RGB;
		else if (nrChannels == 4)
			bitDepth = GL_RGBA;

		glTexImage2D(GL_TEXTURE_2D, 0, bitDepth, width, height, 0, bitDepth, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

}