#pragma once
#include <vector>
#include "Entity.h"
#include "EventHandler.h"


class InteractableEntity : public Entity
{
public:
	InteractableEntity(RawEntity& rawEntity, Texture& texture, Vector3f worldTranslation, Vector3f worldRotation, float worldScale);
	void update();
	EventHandler& getEventHandler();
	
private:
	EventHandler m_eventHandler;

	void moveForward();
	void moveBackward();
	void moveRight();
	void moveLeft();
};