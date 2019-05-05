#include "EventHandler.h"

void EventHandler::addEventToList(Event aEvent)
{
	m_eventList.push_back(aEvent);
}

void EventHandler::removeEventFromList(Event aEvent)
{
	for (std::vector<Event>::iterator it = m_eventList.begin(); it != m_eventList.end();)
	{
		if (aEvent.state == it->state)
		{
			it = m_eventList.erase(it);
			return;
		}
		else
			it++;
	}}

void EventHandler::deleteOneFrameEventsFromList()
{
	for (std::vector<Event>::iterator it = m_eventList.begin(); it != m_eventList.end();)
	{
		if (it->isOneFrameEvent)
			it = m_eventList.erase(it);
		else
			it++;
	}
}

std::vector<Event>& EventHandler::getEventList()
{
	return m_eventList;
}
