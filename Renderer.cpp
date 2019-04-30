#include "Renderer.h"
#include <GLAD\glad.h>
#include <GLFW\glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


void Renderer::renderEntities(EntityShaderProgram& entityShaderProgram, Camera& camera, std::vector<Entity*> entityList)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	entityShaderProgram.useProgram();

	entityShaderProgram.loadViewPos(camera);
	entityShaderProgram.loadViewMatrix(camera);

	for (Entity* entity : entityList)
	{
		entityShaderProgram.loadTransformationMatrix(*entity);
		entityShaderProgram.loadTexture(entity->getTextureUnit());

		glBindVertexArray(entity->getVaoID());
		glDrawElements(GL_TRIANGLES, entity->getIndexCount(), GL_UNSIGNED_INT, 0);
	}

	entityShaderProgram.stopProgram();
}

