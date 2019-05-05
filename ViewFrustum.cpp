#include "ViewFrustum.h"

ViewFrustum::ViewFrustum(float width, float height, float fov, float nearPlane, float farPlane)
	: m_width(width), m_height(height), m_fov(fov), m_near(nearPlane), m_far(farPlane)
{
}

void ViewFrustum::update(float deltaTime)
{
	std::vector<Event>& eventList = m_eventHandler.getEventList();
	if (eventList.empty())
		return;

	for (std::vector<Event>::iterator it = eventList.begin(); it != eventList.end(); ++it)
	{
		if (Event::WINDOW_RESIZE == it->state)
		{
			setWidth(it->x);
			setHeight(it->y);
		}
		else
			it->isOneFrameEvent = true;

	}
	m_eventHandler.deleteOneFrameEventsFromList();
}

void ViewFrustum::addEventToList(Event aEvent)
{
	m_eventHandler.addEventToList(aEvent);
}

void ViewFrustum::removeEventFromList(Event aEvent)
{
	m_eventHandler.removeEventFromList(aEvent);
}

float ViewFrustum::getWidth()
{
	return m_width;
}

float ViewFrustum::getHeight()
{
	return m_height;
}

float ViewFrustum::getFov()
{
	return m_fov;
}

float ViewFrustum::getNear()
{
	return m_near;
}

float ViewFrustum::getFar()
{
	return m_far;
}

void ViewFrustum::setWidth(float width)
{
	m_width = width;
}

void ViewFrustum::setHeight(float height)
{
	m_height = height;
}
