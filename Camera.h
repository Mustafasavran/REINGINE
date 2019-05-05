#pragma once
#include "Vector3f.h"
#include "EventHandler.h"
#include "IUpdatable.h"
#include <vector>


class Camera : public IUpdatable
{
public:
	Camera(Vector3f positionVec, Vector3f frontVec, Vector3f upVec);
	void update(float deltaTime);
	void addEventToList(Event aEvent);
	void removeEventFromList(Event aEvent);
	Vector3f getPositionVec();
	Vector3f getFrontVec();
	Vector3f getUpVec();
	void increasePositionVec(float dx, float dy, float dz);

private:
	EventHandler m_eventHandler;

	Vector3f m_positionVec;
	Vector3f m_frontVec;
	Vector3f m_upVec;
	
	void moveDelta(double xoffset, double yoffset);
	void moveVertical(double xoffset, double yoffset);
};