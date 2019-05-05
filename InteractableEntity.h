#pragma once
#include <vector>
#include "Entity.h"
#include "EventHandler.h"
#include "Event.h"
#include "IUpdatable.h"

class InteractableEntity : public Entity, public IUpdatable
{
public:
	InteractableEntity(RawEntity& rawEntity, Texture& texture, Vector3f worldTranslation, Vector3f worldRotation, float worldScale);
	void update(float deltaTime);
	void addEventToList(Event aEvent);
	void removeEventFromList(Event aEvent);
private:
	EventHandler m_eventHandler;

	void moveForward(float deltaTime);
	void moveBackward(float deltaTime);
	void moveRight(float deltaTime);
	void moveLeft(float deltaTime);
	void rotateAroundYAxis(float deltaTime);
	bool moveTo(Vector3f pos, float deltaTime);
};