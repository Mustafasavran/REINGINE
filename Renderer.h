#pragma once
#include <vector>
#include "Entity.h"
#include "ShaderProgram.h"
#include "EntityShaderProgram.h"
#include "Camera.h"
#include "Window.h"
#include "ViewFrustum.h"


namespace Renderer
{
	void renderEntities(EntityShaderProgram& entityShaderProgram, Camera& camera, ViewFrustum& frustum, std::vector<Entity*> entityList);
}