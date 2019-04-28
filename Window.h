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
	void windowShouldClose();
	void update();
	unsigned int getWindowHeight();
	unsigned int getWindowWidth();
	
private:
	GLFWwindow* m_window;
	unsigned int m_windowHeight;
	unsigned int m_windowWidth;
	friend void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	friend void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
};
