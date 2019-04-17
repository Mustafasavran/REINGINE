#pragma once
#include <vector>
#include "Entity.h"
#include "ShaderProgram.h"
#include "Window.h"

class Renderer
{
public:
	static void render(Window& window, ShaderProgram& shaderProgram, std::vector<Entity*> entityList);
};