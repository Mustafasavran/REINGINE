#pragma once
#include <vector>
#include "Entity.h"
#include "ShaderProgram.h"
#include "Window.h"


namespace Renderer
{
	void render(Window& window, ShaderProgram& shaderProgram, std::vector<Entity*> entityList);
}