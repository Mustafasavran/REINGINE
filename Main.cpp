#include <vector>
#include "ShaderProgram.h"
#include "Entity.h"
#include "Renderer.h"
#include "Window.h"

int main()
{
	float vertices[] = {
		0.5f,  0.5f, 0.0f,  // top right
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};
	
	Window window(600, 600, std::string("Kaimon"));
	ShaderProgram shaderProgram("res/shaders/VertexShader.vert", "res/shaders/FragmentShader.frag");
	Entity entity(vertices, sizeof(vertices) / sizeof(float), indices, sizeof(indices) / sizeof(unsigned int));
	std::vector<Entity*> entityList = { &entity };


	while (!window.isWindowShouldClose())
	{
		window.processInput();
		Renderer::render(shaderProgram, entityList);
		window.update();
	}

	return 0;
}


