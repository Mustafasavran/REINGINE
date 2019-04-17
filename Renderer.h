#pragma once
#include <vector>
#include "Entity.h"
#include "ShaderProgram.h"

class Renderer
{
public:
	static void render(ShaderProgram& shaderProgram, std::vector<Entity*> entityList);
};