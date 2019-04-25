#pragma once
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ShaderProgram
{
public:
	ShaderProgram(std::string vertexPath, std::string fragmentPath);
	virtual ~ShaderProgram();
	void useProgram();
	void stopProgram();
	void setUniform4f(std::string variableName, float x, float y, float z, float w);
	void setUniform1i(std::string variableName, int x);
	void setUniform4fv(std::string variableName, float* mat4);
	bool isProgramUsed();

private:
	void init(std::string vertexPath, std::string fragmentPath);
	unsigned int m_programID;
	bool m_isProgramUsed;
};