#pragma once
#include <string>

class ShaderProgram
{
public:
	ShaderProgram(std::string vertexPath, std::string fragmentPath);
	~ShaderProgram();
	void useProgram();
	void stopProgram();
	void setUniform4f(std::string variableName, float x, float y, float z, float w);

private:
	void init(std::string vertexPath, std::string fragmentPath);
	unsigned int m_programID;
};