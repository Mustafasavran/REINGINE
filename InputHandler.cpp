#include "InputHandler.h"

InputHandler::InputHandler(Window& window, RayCaster& rayCaster, std::vector<IUpdatable*>& updatableList)
	: m_window(window), m_rayCaster(rayCaster), m_updatableList(updatableList)
{
	glfwSetWindowUserPointer(window.getWindow(), this);
}

// algorithm here is dogshit
void InputHandler::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		m_window.windowShouldClose();

	for (IUpdatable* updatable : m_updatableList)
	{
		if (key == GLFW_KEY_W && action == GLFW_PRESS)
			updatable->addEventToList(Event(Event::KEY_W, false));
		else if (key == GLFW_KEY_W && action == GLFW_RELEASE)
			updatable->removeEventFromList(Event(Event::KEY_W, false));
		else if (key == GLFW_KEY_S && action == GLFW_PRESS)
			updatable->addEventToList(Event(Event::KEY_S, false));
		else if (key == GLFW_KEY_S && action == GLFW_RELEASE)
			updatable->removeEventFromList(Event(Event::KEY_S, false));
		else if (key == GLFW_KEY_A && action == GLFW_PRESS)
			updatable->addEventToList(Event(Event::KEY_A, false));
		else if (key == GLFW_KEY_A && action == GLFW_RELEASE)
			updatable->removeEventFromList(Event(Event::KEY_A, false));
		else if (key == GLFW_KEY_D && action == GLFW_PRESS)
			updatable->addEventToList(Event(Event::KEY_D, false));
		else if (key == GLFW_KEY_D && action == GLFW_RELEASE)
			updatable->removeEventFromList(Event(Event::KEY_D, false));
		else if (key == GLFW_KEY_R && action == GLFW_PRESS)
			updatable->addEventToList(Event(Event::KEY_R, false));
		else if (key == GLFW_KEY_R && action == GLFW_RELEASE)
			updatable->removeEventFromList(Event(Event::KEY_R, false));
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
		
		for (IUpdatable* updatable : m_updatableList)
			updatable->addEventToList(Event(Event::MOUSE_BUTTON_MIDDLE_DRAGGED, true, float(xoffset), float(yoffset)));
	}
	else
	{
		m_prevXposition = xpos;
		m_prevYposition = ypos;
	}
}

void InputHandler::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	for (IUpdatable* updatable : m_updatableList)
		updatable->addEventToList(Event(Event::MOUSE_SCROLL, true, float(xoffset), float(yoffset)));
}

void InputHandler::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		m_rayCaster.addEventToList(Event(Event::MOUSE_BUTTON_RIGHT_PRESSED, true, float(xpos), float(ypos)));
	}
}

void InputHandler::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	for (IUpdatable* updatable : m_updatableList)
		updatable->addEventToList(Event(Event::WINDOW_RESIZE, true, float(width), float(height)));
}
