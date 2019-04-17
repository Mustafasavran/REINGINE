#include <vector>
#include "ShaderProgram.h"
#include "Entity.h"
#include "Renderer.h"
#include "Window.h"
#include "Texture.h"
#include "Vector3f.h"


int main()
{
	std::vector<float> vertices = {
		0.5f,  0.5f, 0.0f,  1.0f, 1.0f, // top right
		0.5f, -0.5f, 0.0f,  1.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
		-0.5f,  0.5f, 0.0f, 0.0f, 1.0f  // top left 
	};

	std::vector<unsigned int> indices = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};
	
	
	Window window(600, 600, std::string("Kaimon"));
	ShaderProgram shaderProgram("res/shaders/VertexShader.vert", "res/shaders/FragmentShader.frag");
	Entity entity1(Vector3f(2.0f, 0.0f, -5.0f), Vector3f(0.0f, 45.0f, 0.0f), 1.0f, vertices, indices);
	Entity entity2(Vector3f(0.0f, 0.0f, -2.0f), Vector3f(0.0f, 45.0f, 0.0f), 1.0f, vertices, indices);
	std::vector<Entity*> entityList = { &entity1, &entity2 };
	Texture texture1("res/textures/container.jpg", 0);
	Texture texture2("res/textures/awesomeface.png", 1);

	
	while (!window.isWindowShouldClose())
	{
		window.processInput();
		entity2.increaseRotationVector(0.0f, 1.0f, 0.0f);
		Renderer::render(window, shaderProgram, entityList);
		window.update();
	}

	return 0;
}


