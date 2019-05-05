#include "Window.h"
#include <iostream>
#include "InputHandler.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

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
	glfwSetKeyCallback(m_window, key_callback);
	glfwSetCursorPosCallback(m_window, cursor_position_callback);
	glfwSetScrollCallback(m_window, scroll_callback);
	glfwSetMouseButtonCallback(m_window, mouse_button_callback);
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

void Window::windowShouldClose()
{
	glfwSetWindowShouldClose(m_window, true);
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

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	InputHandler* inputHandler = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
	inputHandler->key_callback(window, key, scancode, action, mods);
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	InputHandler* inputHandler = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
	inputHandler->cursor_position_callback(window, xpos, ypos);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	InputHandler* inputHandler = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
	inputHandler->scroll_callback(window, xoffset, yoffset);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	InputHandler* inputHandler = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
	inputHandler->mouse_button_callback(window, button, action, mods);
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	InputHandler* inputHandler = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
	inputHandler->framebuffer_size_callback(window, width, height);
}