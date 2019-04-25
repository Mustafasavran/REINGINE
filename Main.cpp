#include <vector>
#include "EntityShaderProgram.h"
#include "Entity.h"
#include "RawEntity.h"
#include "Renderer.h"
#include "Window.h"
#include "Texture.h"
#include "Vector3f.h"
#include "OBJLoader.h"
#include "Terrain.h"
#include "Camera.h"


int main()
{
	Window window(800, 450, std::string("Kaimon"));
	EntityShaderProgram entityShaderProgram("res/shaders/VertexShader.vert", "res/shaders/FragmentShader.frag");
	entityShaderProgram.loadProjectionMatrix(800.0f, 450.0f, 60.0f, 0.1f, 100.0f);
	Camera camera(Vector3f(0.0f, 10.0f, 5.0f), Vector3f(0.0f, -2.0f, -1.0f), Vector3f(0.0f, 1.0f, 0.0f));

	RawEntity rawEntity = OBJLoader::loadFile("res/models/wallCube.obj");
	RawEntity rawTerrain = Terrain::createTerrain(20, 20);
	Texture texture1("res/textures/checker128.png", 0);
	Texture texture2("res/textures/wall.jpg", 1);

	Entity terrain(rawTerrain, texture1, Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f), 1.0f);
	Entity entity(rawEntity, texture2, Vector3f(0.0f, 1.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f), 1.0f);
	std::vector<Entity*> entityList = { &terrain, &entity };
	
	while (!window.isWindowShouldClose())
	{
		window.processInput();
		// entity.increaseRotationVector(0.0f, 1.0f, 0.0f);
		Renderer::renderEntities(entityShaderProgram, camera, entityList);
		window.update();
	}

	return 0;
}


