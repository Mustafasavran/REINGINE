#include "Camera.h"

Camera::Camera(Vector3f positionVec, Vector3f frontVec, Vector3f upVec)
	:	m_positionVec(positionVec), m_frontVec(frontVec), m_upVec(upVec)
{
}

void Camera::update()
{
	std::vector<Event> eventList = m_eventHandler.getEventList();
	if (eventList.empty())
		return;

	for (std::vector<Event>::iterator it = eventList.begin(); it != eventList.end(); ++it)
	{
		if (Event::MOUSE_BUTTON_MIDDLE_DRAGGED == it->state)
			moveDelta(it->x, it->y);
		else if (Event::MOUSE_SCROLL == it->state)
			moveVertical(it->x, it->y);
	}
	m_eventHandler.deleteOneFrameEventsFromList();
}

EventHandler& Camera::getEventHandler()
{
	return m_eventHandler;
}

Vector3f Camera::getPositionVec()
{
	return m_positionVec;
}

Vector3f Camera::getFrontVec()
{
	return m_frontVec;
}

Vector3f Camera::getUpVec()
{
	return m_upVec;
}

void Camera::increasePositionVec(float dx, float dy, float dz)
{
	m_positionVec.increasePosition(dx, dy, dz);
}


void Camera::moveDelta(double xoffset, double yoffset)
{	
	float dx = float(xoffset * 0.02);
	float dz = float(yoffset * 0.02);

	increasePositionVec(-dx, 0.0f, dz);
}

void Camera::moveVertical(double xoffset, double yoffset)
{
	if (yoffset == 1.0 && m_positionVec.y <= 5)
		return;

	float ratio = -yoffset * (m_frontVec.y / m_frontVec.z);
	float dx = ratio / 6.0f;
	float dy = -yoffset / 6.0f;
	increasePositionVec(0.0f, dx, dy);
}
