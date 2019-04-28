#pragma once

class Event
{
public:
	enum State
	{
		MOUSE_BUTTON_MIDDLE_PRESSED,
		MOUSE_BUTTON_MIDDLE_RELEASED,
		MOUSE_BUTTON_MIDDLE_DRAGGED,
		MOUSE_SCROLL,

		KEY_W, KEY_S, KEY_A, KEY_D,
		KEY_UP, KEY_DOWN
	};
	
	State state;
	bool isOneFrameEvent;	
	double x, y;

	Event(State state, bool isOneFrameEvent, double x = 0, double y = 0) : state(state), isOneFrameEvent(isOneFrameEvent), x(x), y(y) { }
};
