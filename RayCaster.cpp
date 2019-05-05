#include "RayCaster.h"
#include "MathCalc.h"

RayCaster::RayCaster(Camera& camera, ViewFrustum& frustum, std::vector<IUpdatable*>& updatableList)
	: m_camera(camera), m_frustum(frustum), m_updatableList(updatableList)
{
}

void RayCaster::update(float deltaTime)
{
	std::vector<Event>& eventList = m_eventHandler.getEventList();
	if (eventList.empty())
		return;

	for (std::vector<Event>::iterator it = eventList.begin(); it != eventList.end(); ++it)
	{
		if (Event::MOUSE_BUTTON_RIGHT_PRESSED == it->state)
		{
			Vector3f vec3 = MathCalc::createRayCast(m_camera, m_frustum, it->x, it->y);
			Vector3f interVec = MathCalc::findIntersectionPointForXPlane(vec3, m_camera);
			
			for (IUpdatable* updatable : m_updatableList)
			{
				updatable->removeEventFromList(Event(Event::MOUSE_BUTTON_RIGHT_PRESSED, false, interVec.x, interVec.y, interVec.z));
				updatable->addEventToList(Event(Event::MOUSE_BUTTON_RIGHT_PRESSED, false, interVec.x, interVec.y, interVec.z));
			}
		}
		else
			it->isOneFrameEvent = true;

	}
	m_eventHandler.deleteOneFrameEventsFromList();
}

void RayCaster::addEventToList(Event aEvent)
{
	m_eventHandler.addEventToList(aEvent);
}

void RayCaster::removeEventFromList(Event aEvent)
{
	m_eventHandler.removeEventFromList(aEvent);
}

Vector3f RayCaster::castRay(float xpos, float ypos)
{
	return MathCalc::createRayCast(m_camera, m_frustum, xpos, ypos);
}

Vector3f RayCaster::findIntersectionPointForXPlane(Vector3f ray)
{
	return MathCalc::findIntersectionPointForXPlane(ray, m_camera);
}
