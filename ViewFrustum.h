#pragma once
#include "IUpdatable.h"
#include "EventHandler.h"

class ViewFrustum : public IUpdatable
{
public:
	ViewFrustum(float width, float height, float fov, float nearPlane, float farPlane);

	void update(float deltaTime);
	void addEventToList(Event aEvent);
	void removeEventFromList(Event aEvent);

	float getWidth();
	float getHeight();
	float getFov();
	float getNear();
	float getFar();

	void setWidth(float width);
	void setHeight(float height);

private:
	EventHandler m_eventHandler;

	float m_width;
	float m_height;
	float m_fov;
	float m_near;
	float m_far;
};