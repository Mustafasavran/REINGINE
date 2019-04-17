#include "Renderer.h"
#include <GLAD\glad.h>
#include <GLFW\glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


void Renderer::render(Window& window, ShaderProgram& shaderProgram, std::vector<Entity*> entityList)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	shaderProgram.useProgram();
	
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);
	
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.0f));
	projection = glm::perspective(glm::radians(90.0f), (float)window.getWindowWidth() / (float)window.getWindowHeight(), 0.1f, 100.0f);

	shaderProgram.setUniform4fv("view", glm::value_ptr(view));
	shaderProgram.setUniform4fv("projection", glm::value_ptr(projection));
	shaderProgram.setUniform1i("texture1", 0);
	shaderProgram.setUniform1i("texture2", 1);

	for (Entity* entity : entityList)
	{
		glm::mat4 model = glm::mat4(1.0f);

		model = glm::translate(model, glm::vec3(entity->getTranslationVector().x, entity->getTranslationVector().y, entity->getTranslationVector().z));
		model = glm::rotate(model, glm::radians(entity->getRotationVector().z), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, glm::radians(entity->getRotationVector().y), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(entity->getRotationVector().x), glm::vec3(1.0f, 0.0f, 0.0f));
		
		shaderProgram.setUniform4fv("model", glm::value_ptr(model));

		glBindVertexArray(entity->getVaoID());
		glDrawElements(GL_TRIANGLES, entity->getIndexCount(), GL_UNSIGNED_INT, 0);
	}

	shaderProgram.stopProgram();
}