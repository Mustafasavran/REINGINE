#pragma once
#include "ShaderProgram.h"
#include "Entity.h"
#include "Camera.h"
#include "Texture.h"
#include "Light.h"
#include "ViewFrustum.h"

class EntityShaderProgram : public ShaderProgram
{
public:
	EntityShaderProgram(std::string vertexPath, std::string fragmentPath);
	void loadTransformationMatrix(Entity& entity);
	void loadViewMatrix(Camera& camera);
	void loadProjectionMatrix(ViewFrustum& frustum);
	void loadTexture(unsigned int textureUnit);
	void loadViewPos(Camera& camera);
	void loadLight(Light& light);
};