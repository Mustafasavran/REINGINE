#pragma once

class Event
{
public:
	enum State
	{
		MOUSE_BUTTON_MIDDLE_PRESSED,
		MOUSE_BUTTON_MIDDLE_RELEASED,
		MOUSE_BUTTON_MIDDLE_DRAGGED,
		MOUSE_BUTTON_RIGHT_PRESSED,
		MOUSE_BUTTON_RIGHT_RELEASED,
		MOUSE_SCROLL,

		KEY_W, KEY_S, KEY_A, KEY_D,
		KEY_R, 
		KEY_UP, KEY_DOWN,
		WINDOW_RESIZE
	};
	
	State state;
	bool isOneFrameEvent;	
	float x, y, z;

	Event(State state, bool isOneFrameEvent, float x = 0.0f, float y = 0.0f, float z = 0.0f) : state(state), isOneFrameEvent(isOneFrameEvent), x(x), y(y), z(z) { }
};
