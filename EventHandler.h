#pragma once
#include <vector>
#include "Event.h"

class EventHandler
{
public:
	void addEventToList(Event aEvent);
	void removeEventFromList(Event aEvent);
	void deleteOneFrameEventsFromList();
	std::vector<Event>& getEventList();

private:
	std::vector<Event> m_eventList;
};