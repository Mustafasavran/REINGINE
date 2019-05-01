#pragma once
#include <GLFW\glfw3.h>

class Timer
{
public:
	float getDeltaTime()
	{
		float currentFrameTime = float(glfwGetTime());
		float deltaTime = currentFrameTime - m_lastFrameTime;
		m_lastFrameTime = currentFrameTime;
		return deltaTime;
	}

	float getLastFrameTime() { return m_lastFrameTime; }

private:
	float m_lastFrameTime = 0.0f;
};