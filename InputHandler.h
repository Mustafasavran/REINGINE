#pragma once
#include <vector>
#include "Window.h"
#include "Camera.h"
#include "InteractableEntity.h"
#include "ViewFrustum.h"
#include "MathCalc.h"
#include "IUpdatable.h"
#include "RayCaster.h"

class InputHandler
{
public:
	InputHandler(Window& window, RayCaster& rayCaster, std::vector<IUpdatable*>& updatableList);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void cursor_position_callback(GLFWwindow * window, double xpos, double ypos);
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);

private:
	Window& m_window;
	std::vector<IUpdatable*>& m_updatableList;
	RayCaster& m_rayCaster;

	double m_prevXposition;
	double m_prevYposition;
};
