#pragma once
#include <vector>
#include "Window.h"
#include "Camera.h"
#include "InteractableEntity.h"

class InputHandler
{
public:
	InputHandler(Window& window, Camera& camera, std::vector<InteractableEntity*>& entityList);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void cursor_position_callback(GLFWwindow * window, double xpos, double ypos);
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

private:
	Window& m_window;
	Camera& m_camera;
	std::vector<InteractableEntity*>& m_entityList;

	double m_prevXposition;
	double m_prevYposition;
};
