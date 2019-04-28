#include "Entity.h"
#include <GLAD\glad.h>

Entity::Entity(RawEntity& rawEntity, Texture& texture, Vector3f worldTranslation, Vector3f worldRotation, float worldScale)
	: m_rawEntity(rawEntity), m_texture(texture), m_translationVector(worldTranslation), m_rotationVector(worldRotation), m_scale(worldScale)
{
}

Entity::~Entity()
{
}

Vector3f Entity::getTranslationVector()
{
	return m_translationVector;
}

Vector3f Entity::getRotationVector()
{
	return m_rotationVector;
}

float Entity::getScale()
{
	return m_scale;
}

void Entity::increaseTranslationVector(float dx, float dy, float dz)
{
	m_translationVector.increasePosition(dx, dy, dz);
}

void Entity::increaseRotationVector(float dx, float dy, float dz)
{
	m_rotationVector.increasePosition(dx, dy, dz);
}

void Entity::increaseScale(float ds)
{
	m_scale += ds;
}

unsigned int Entity::getVaoID()
{
	return m_rawEntity.getVaoID();
}

unsigned int Entity::getTextureID()
{
	return m_texture.getTextureID();
}

unsigned int Entity::getTextureUnit()
{
	return m_texture.getTextureUnit();
}

unsigned int Entity::getIndexCount()
{
	return m_rawEntity.indexCount();
}

unsigned int Entity::getVertexCount()
{
	return m_rawEntity.vertexCount();
}
