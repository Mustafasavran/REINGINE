#pragma once
#include <vector>
#include "Entity.h"
#include "EventHandler.h"


class InteractableEntity : public Entity
{
public:
	InteractableEntity(RawEntity& rawEntity, Texture& texture, Vector3f worldTranslation, Vector3f worldRotation, float worldScale);
	void update(float deltaTime);
	EventHandler& getEventHandler();
	
private:
	EventHandler m_eventHandler;

	void moveForward(float deltaTime);
	void moveBackward(float deltaTime);
	void moveRight(float deltaTime);
	void moveLeft(float deltaTime);
	void rotateAroundYAxis(float deltaTime);
};