#include "InteractableEntity.h"
#include <iostream>

InteractableEntity::InteractableEntity(RawEntity& rawEntity, Texture& texture, Vector3f worldTranslation, Vector3f worldRotation, float worldScale)
	: Entity(rawEntity, texture, worldTranslation, worldRotation, worldScale)
{
}

void InteractableEntity::update()
{
	std::vector<Event> eventList = m_eventHandler.getEventList();
	if (eventList.empty())
		return;

	for (std::vector<Event>::iterator it = eventList.begin(); it != eventList.end(); ++it)
	{
		if (Event::KEY_W == it->state)
			moveForward();
	}
	m_eventHandler.deleteOneFrameEventsFromList();
}

EventHandler& InteractableEntity::getEventHandler()
{
	return m_eventHandler;
}


void InteractableEntity::moveForward()
{
	increaseTranslationVector(0.0f, 0.0f, -2.0f / 60.0f);
}

void InteractableEntity::moveBackward()
{
	increaseTranslationVector(0.0f, 0.0f, 2.0f / 60.0f);
}

void InteractableEntity::moveRight()
{
	increaseTranslationVector(2.0f / 60.0f, 0.0f, 0.0f);
}

void InteractableEntity::moveLeft()
{
	increaseTranslationVector(-2.0f / 60.0f, 0.0f, 0.0f);
}
