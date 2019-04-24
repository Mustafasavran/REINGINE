#include "Window.h"
#include <iostream>

Window::Window(int windowWidth, int windowHeight, std::string windowName)
	: m_windowHeight(windowHeight), m_windowWidth(windowWidth)
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(windowWidth, windowHeight, windowName.c_str(), NULL, NULL);
	if (m_window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(m_window);
	glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	glEnable(GL_DEPTH_TEST);
}

Window::~Window()
{
	glfwTerminate();
}

void Window::processInput()
{
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(m_window, true);
}

void Window::update()
{
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

bool Window::isWindowShouldClose()
{
	if (glfwWindowShouldClose(m_window))
		return true;
	else
		return false;
}

GLFWwindow* Window::getWindow()
{
	return m_window;
}

unsigned int Window::getWindowHeight()
{
	return m_windowHeight;
}

unsigned int Window::getWindowWidth()
{
	return m_windowWidth;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}