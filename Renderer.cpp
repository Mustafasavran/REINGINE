#include "Renderer.h"
#include <GLAD\glad.h>
#include <GLFW\glfw3.h>

void Renderer::render(ShaderProgram& shaderProgram, std::vector<Entity*> entityList)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	shaderProgram.useProgram();

	float timeValue = glfwGetTime();
	float greenValue = sin(timeValue) / 2.0f + 0.5f;
	shaderProgram.setUniform4f(std::string("outColor"), 0.0f, greenValue, 0.0f, 1.0f);

	for (Entity* entity : entityList)
	{
		glBindVertexArray(entity->getVaoID());
		glDrawElements(GL_TRIANGLES, entity->getIndexCount(), GL_UNSIGNED_INT, 0);
	}

	shaderProgram.stopProgram();

}