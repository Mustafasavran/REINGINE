#include "EntityShaderProgram.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

EntityShaderProgram::EntityShaderProgram(std::string vertexPath, std::string fragmentPath)
	: ShaderProgram(vertexPath, fragmentPath)
{
	
}

void EntityShaderProgram::loadTransformationMatrix(Entity& entity)
{
	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(model, glm::vec3(entity.getTranslationVector().x, entity.getTranslationVector().y, entity.getTranslationVector().z));
	model = glm::rotate(model, glm::radians(entity.getRotationVector().z), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::rotate(model, glm::radians(entity.getRotationVector().y), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, glm::radians(entity.getRotationVector().x), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::scale(model, glm::vec3(entity.getScale(), entity.getScale(), entity.getScale()));

	if(isProgramUsed())
		setUniform4fv("model", glm::value_ptr(model));
	else
	{
		useProgram();
		setUniform4fv("model", glm::value_ptr(model));
		stopProgram();
	}

}

void EntityShaderProgram::loadViewMatrix(Camera& camera)
{
	glm::mat4 view = glm::mat4(1.0f);
	glm::vec3 cameraFront = glm::vec3(camera.getFrontVec().x, camera.getFrontVec().y, camera.getFrontVec().z);
	glm::vec3 cameraPos = glm::vec3(camera.getPositionVec().x, camera.getPositionVec().y, camera.getPositionVec().z);
	glm::vec3 cameraUp = glm::vec3(camera.getUpVec().x, camera.getUpVec().y, camera.getUpVec().z);
	cameraFront = glm::normalize(cameraFront);

	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	
	if (isProgramUsed())
		setUniform4fv("view", glm::value_ptr(view));
	else
	{
		useProgram();
		setUniform4fv("view", glm::value_ptr(view));
		stopProgram();
	}

}

void EntityShaderProgram::loadProjectionMatrix(float width, float height, float fov, float near, float far)
{
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(fov), width / height, near, far);

	if(isProgramUsed())
		setUniform4fv("projection", glm::value_ptr(projection));
	else
	{
		useProgram();
		setUniform4fv("projection", glm::value_ptr(projection));
		stopProgram();
	}
}

void EntityShaderProgram::loadTexture(unsigned int textureUnit)
{
	if(isProgramUsed())
		setUniform1i("texture1", textureUnit);
	else
	{
		useProgram();
		setUniform1i("texture1", textureUnit);
		stopProgram();
	}
}

void EntityShaderProgram::loadViewPos(Camera& camera)
{
	if (isProgramUsed())
		setUniform3f("viewPos", camera.getPositionVec().x, camera.getPositionVec().y, camera.getPositionVec().z);
	else
	{
		useProgram();
		setUniform3f("viewPos", camera.getPositionVec().x, camera.getPositionVec().y, camera.getPositionVec().z);
		stopProgram();
	}
}
