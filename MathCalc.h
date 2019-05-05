#pragma once
#include "Entity.h"
#include "Camera.h"
#include "Vector3f.h"
#include "ViewFrustum.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_inverse.hpp>


namespace MathCalc
{
	void createTransformationMatrix(Entity& entity, float* fArray);
	void createViewMatrix(Camera& camera, float* fArray);
	void createProjectionMatrix(float width, float height, float fov, float nearPlane, float farPlane, float* fArray);
	Vector3f createRayCast(Camera& camera, ViewFrustum& frustum, float xpos, float ypos);
	Vector3f findIntersectionPointForXPlane(Vector3f ray, Camera& camera);
}