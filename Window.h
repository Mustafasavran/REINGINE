#pragma once
#include <GLAD\glad.h>
#include <GLFW\glfw3.h>
#include <string>

class Window
{
public:
	Window(int width, int height, std::string windowName);
	~Window();
	GLFWwindow* getWindow();
	bool isWindowShouldClose();
	void processInput();
	void update();
	unsigned int getWindowHeight();
	unsigned int getWindowWidth();
	
private:
	GLFWwindow* m_window;
	unsigned int m_windowHeight;
	unsigned int m_windowWidth;
	friend void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};
