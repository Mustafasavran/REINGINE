#pragma once
#include <GLFW/glfw3.h>
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
	
private:
	GLFWwindow* m_window;
	friend void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};
