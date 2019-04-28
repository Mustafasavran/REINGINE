#include "InputHandler.h"

InputHandler::InputHandler(Window& window, Camera& camera, std::vector<InteractableEntity*>& entityList)
	: m_window(window), m_camera(camera), m_entityList(entityList)
{
	glfwSetWindowUserPointer(window.getWindow(), this);
}

// algorithm here is dogshit
void InputHandler::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		m_window.windowShouldClose();

	for (InteractableEntity* interactableEntity : m_entityList)
	{ 
		if (key == GLFW_KEY_W && action == GLFW_PRESS)
			interactableEntity->getEventHandler().addEventToList(Event(Event::KEY_W, false));
		else if (key == GLFW_KEY_W && action == GLFW_RELEASE)
			interactableEntity->getEventHandler().removeEventFromList(Event(Event::KEY_W, false));
	}

}

void InputHandler::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{	
	if (glfwGetMouseButton(m_window.getWindow(), GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS)
	{
		double xoffset = xpos - m_prevXposition;
		double yoffset = m_prevYposition - ypos; // reversed since y-coordinates go from bottom to top
		m_prevXposition = xpos;
		m_prevYposition = ypos;

		m_camera.getEventHandler().addEventToList(Event(Event::MOUSE_BUTTON_MIDDLE_DRAGGED, true, xoffset, yoffset));
	}
	else
	{
		m_prevXposition = xpos;
		m_prevYposition = ypos;
	}
}

void InputHandler::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	m_camera.getEventHandler().addEventToList(Event(Event::MOUSE_SCROLL, true, xoffset, yoffset));
}
