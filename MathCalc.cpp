#include "MathCalc.h"

namespace MathCalc
{

	void createTransformationMatrix(Entity& entity, float* fArray)
	{
		glm::mat4 model = glm::mat4(1.0f);

		model = glm::translate(model, glm::vec3(entity.getTranslationVector().x, entity.getTranslationVector().y, entity.getTranslationVector().z));
		model = glm::rotate(model, glm::radians(entity.getRotationVector().z), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, glm::radians(entity.getRotationVector().y), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(entity.getRotationVector().x), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(entity.getScale(), entity.getScale(), entity.getScale()));
		
		const float *pSource = (const float*)glm::value_ptr(model);
		for (int i = 0; i < 16; ++i)
			fArray[i] = pSource[i];
	}

	void createViewMatrix(Camera& camera, float* fArray)
	{
		glm::mat4 view = glm::mat4(1.0f);
		glm::vec3 cameraFront = glm::vec3(camera.getFrontVec().x, camera.getFrontVec().y, camera.getFrontVec().z);
		glm::vec3 cameraPos = glm::vec3(camera.getPositionVec().x, camera.getPositionVec().y, camera.getPositionVec().z);
		glm::vec3 cameraUp = glm::vec3(camera.getUpVec().x, camera.getUpVec().y, camera.getUpVec().z);
		cameraFront = glm::normalize(cameraFront);

		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

		const float *pSource = (const float*)glm::value_ptr(view);
		for (int i = 0; i < 16; ++i)
			fArray[i] = pSource[i];
	}

	void createProjectionMatrix(float width, float height, float fov, float nearPlane, float farPlane, float* fArray)
	{
		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(fov), width / height, nearPlane, farPlane);

		const float *pSource = (const float*)glm::value_ptr(projection);
		for (int i = 0; i < 16; ++i)
			fArray[i] = pSource[i];
	}

	Vector3f createRayCast(Camera& camera, ViewFrustum& frustum, float xpos, float ypos)
	{
		float x = (2.0f * xpos) / frustum.getWidth() - 1.0f;
		float y = 1.0f - (2.0f * ypos) / frustum.getHeight();
		float z = 1.0f;
		glm::vec3 ray_nds(x, y, z);

		glm::vec4 ray_clip = glm::vec4(ray_nds.x, ray_nds.y, -1.0, 1.0);

		float projectionMatrix[16];
		createProjectionMatrix(frustum.getWidth(), frustum.getHeight(), frustum.getFov(), frustum.getNear(), frustum.getFar(), projectionMatrix);
		glm::vec4 ray_eye = glm::inverse(glm::make_mat4(projectionMatrix)) * ray_clip;
		ray_eye = glm::vec4(ray_eye.x, ray_eye.y, -1.0, 0.0);

		float viewMatrix[16];
		createViewMatrix(camera, viewMatrix);
		
		glm::vec4 ray_wor4 = glm::inverse(glm::make_mat4(viewMatrix)) * ray_eye;
		glm::vec3 ray_wor3(ray_wor4.x, ray_wor4.y, ray_wor4.z);
		// don't forget to normalise the vector at some point
		ray_wor3 = glm::normalize(ray_wor3);
		
		return Vector3f(ray_wor3.x, ray_wor3.y, ray_wor3.z);
	}

	Vector3f findIntersectionPointForXPlane(Vector3f ray, Camera& camera)
	{
		glm::vec3 rayStart(camera.getPositionVec().x, camera.getPositionVec().y, camera.getPositionVec().z);
		float distance = 1000.0f;
		glm::vec3 rayEnd(camera.getPositionVec().x + distance * ray.x, camera.getPositionVec().y + distance * ray.y, camera.getPositionVec().z + distance * ray.z);
		glm::vec3 rayDelta = rayEnd - rayStart;
		glm::vec3 planePos(0.0f, 0.0f, 0.0f);
		glm::vec3 planeNorm(0.0f, 1.0f, 0.0f);
		glm::vec3 rayToPlaneDelta = planePos - rayStart;
		float scale = glm::dot(rayToPlaneDelta, planeNorm) / glm::dot(rayDelta, planeNorm);
		glm::vec3 intersection = rayStart + scale * rayDelta;

		// bool isInter = scale >= 0 && scale <= 1;

		return Vector3f(intersection.x, intersection.y, intersection.z);
	}

}