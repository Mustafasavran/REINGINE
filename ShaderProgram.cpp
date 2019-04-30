#include "ShaderProgram.h"
#include <GLAD\glad.h>
#include <fstream>
#include <sstream>
#include <iostream>

ShaderProgram::ShaderProgram(std::string vertexPath, std::string fragmentPath)
	: m_isProgramUsed(false)
{
	init(vertexPath, fragmentPath);
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(m_programID);
}

void ShaderProgram::setUniform4fv(std::string variableName, float* mat4)
{
	int location = glGetUniformLocation(m_programID, variableName.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, mat4);
}

bool ShaderProgram::isProgramUsed()
{
	return m_isProgramUsed;
}

void ShaderProgram::setUniform3f(std::string variableName, float x, float y, float z)
{
	int location = glGetUniformLocation(m_programID, variableName.c_str());
	glUniform3f(location, x, y, z);
}

void ShaderProgram::setUniform4f(std::string variableName, float x, float y, float z, float w)
{
	int location = glGetUniformLocation(m_programID, variableName.c_str());
	glUniform4f(location, x, y, z, w);
}

void ShaderProgram::setUniform1i(std::string variableName, int x)
{
	int location = glGetUniformLocation(m_programID, variableName.c_str());
	glUniform1i(location, x);
}

void ShaderProgram::init(std::string vertexPath, std::string fragmentPath)
{
	int success;
	char infoLog[512];

	std::string vertexCode, fragmentCode;
	std::ifstream vShaderFile, fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	glCompileShader(vertexShader);

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
	glCompileShader(fragmentShader);

	m_programID = glCreateProgram();
	glAttachShader(m_programID, vertexShader);
	glAttachShader(m_programID, fragmentShader);
	glLinkProgram(m_programID);

	glGetProgramiv(m_programID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(m_programID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void ShaderProgram::useProgram()
{
	glUseProgram(m_programID);
	m_isProgramUsed = true;
}

void ShaderProgram::stopProgram()
{
	glUseProgram(0);
	m_isProgramUsed = false;
}

