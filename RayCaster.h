#pragma once
#include "Camera.h"
#include "ViewFrustum.h"
#include "EventHandler.h"
#include "Vector3f.h"
#include "IUpdatable.h"

class RayCaster : public IUpdatable
{
public:
	RayCaster(Camera& camera, ViewFrustum& frustum, std::vector<IUpdatable*>& updatableList);
	void update(float deltaTime);
	void addEventToList(Event aEvent);
	void removeEventFromList(Event aEvent);

	Vector3f castRay(float xpos, float ypos);
	Vector3f findIntersectionPointForXPlane(Vector3f ray);

private:
	EventHandler m_eventHandler;

	Camera& m_camera;
	ViewFrustum& m_frustum;
	std::vector<IUpdatable*>& m_updatableList;
};
