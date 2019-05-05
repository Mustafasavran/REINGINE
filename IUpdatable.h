#pragma once
#include "Event.h"

class IUpdatable
{
public:
	virtual ~IUpdatable() {}
	virtual void update(float deltaTime) = 0;
	virtual void addEventToList(Event aEvent) = 0;
	virtual void removeEventFromList(Event aEvent) = 0;

};