#pragma once
#include <vector>
#include "Entity.h"
#include "ShaderProgram.h"
#include "EntityShaderProgram.h"
#include "Camera.h"
#include "Window.h"


namespace Renderer
{
	void renderEntities(EntityShaderProgram& entityShaderProgram, Camera& camera, std::vector<Entity*> entityList);
}