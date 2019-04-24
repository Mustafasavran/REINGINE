#include <vector>
#include "ShaderProgram.h"
#include "Entity.h"
#include "RawEntity.h"
#include "Renderer.h"
#include "Window.h"
#include "Texture.h"
#include "Vector3f.h"
#include "OBJLoader.h"


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

	Window window(1280, 720, std::string("Kaimon"));
	ShaderProgram shaderProgram("res/shaders/VertexShader.vert", "res/shaders/FragmentShader.frag");
	RawEntity rawEntity = OBJLoader::loadFile("res/models/wallCube.obj");
	
	Entity entity(rawEntity, Vector3f(0.0f, -2.0f, -5.0f), Vector3f(0.0f, 0.0f, 0.0f), 1.0f);
	std::vector<Entity*> entityList = { &entity };
	Texture texture1("res/textures/wall.jpg", 0);
	//Texture texture2("res/textures/awesomeface.png", 1);

	
	while (!window.isWindowShouldClose())
	{
		window.processInput();
		entity.increaseRotationVector(0.0f, 1.0f, 0.0f);
		Renderer::render(window, shaderProgram, entityList);
		window.update();
	}

	return 0;
}


