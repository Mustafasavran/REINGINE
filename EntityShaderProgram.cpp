#include "EntityShaderProgram.h"
#include "MathCalc.h"

EntityShaderProgram::EntityShaderProgram(std::string vertexPath, std::string fragmentPath)
	: ShaderProgram(vertexPath, fragmentPath)
{
}

void EntityShaderProgram::loadTransformationMatrix(Entity& entity)
{
	float fArray[16];
	MathCalc::createTransformationMatrix(entity, fArray);

	if(isProgramUsed())
		setUniform4fv("model", fArray);
	else
	{
		useProgram();
		setUniform4fv("model", fArray);
		stopProgram();
	}

}

void EntityShaderProgram::loadViewMatrix(Camera& camera)
{
	float fArray[16];
	MathCalc::createViewMatrix(camera, fArray);
	
	if (isProgramUsed())
		setUniform4fv("view", fArray);
	else
	{
		useProgram();
		setUniform4fv("view", fArray);
		stopProgram();
	}

}

void EntityShaderProgram::loadProjectionMatrix(ViewFrustum& frustum)
{
	float fArray[16];
	MathCalc::createProjectionMatrix(frustum.getWidth(), frustum.getHeight(), frustum.getFov(), frustum.getNear(), frustum.getFar(), fArray);
		
	if(isProgramUsed())
		setUniform4fv("projection", fArray);
	else
	{
		useProgram();
		setUniform4fv("projection", fArray);
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

void EntityShaderProgram::loadLight(Light& light)
{
	if (isProgramUsed())
	{
		setUniform3f("light.position", light.getPositionVec().x, light.getPositionVec().y, light.getPositionVec().z);
		setUniform3f("light.ambient", light.getAmbientColor().x, light.getAmbientColor().y, light.getAmbientColor().z);
		setUniform3f("light.diffuse", light.getDiffuseColor().x, light.getDiffuseColor().y, light.getDiffuseColor().z);
		setUniform3f("light.specular", light.getSpecularColor().x, light.getSpecularColor().y, light.getSpecularColor().z);
	}
		
	else
	{
		useProgram();
		setUniform3f("light.position", light.getPositionVec().x, light.getPositionVec().y, light.getPositionVec().z);
		setUniform3f("light.ambient", light.getAmbientColor().x, light.getAmbientColor().y, light.getAmbientColor().z);
		setUniform3f("light.diffuse", light.getDiffuseColor().x, light.getDiffuseColor().y, light.getDiffuseColor().z);
		setUniform3f("light.specular", light.getSpecularColor().x, light.getSpecularColor().y, light.getSpecularColor().z);
		stopProgram();
	}
}
