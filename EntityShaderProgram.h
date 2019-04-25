#pragma once
#include "ShaderProgram.h"
#include "Entity.h"
#include "Camera.h"
#include "Texture.h"

class EntityShaderProgram : public ShaderProgram
{
public:
	EntityShaderProgram(std::string vertexPath, std::string fragmentPath);
	void loadTransformationMatrix(Entity& entity);
	void loadViewMatrix(Camera& camera);
	void loadProjectionMatrix(float width, float height, float fov, float near, float far);
	void loadTexture(unsigned int textureUnit);
};