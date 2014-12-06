#ifndef CORE_INPUT_H
#define CORE_INPUT_H

#include <GLFW\glfw3.h>
#include <GLM\glm.hpp>

typedef glm::vec2 vec2;

static const int NUM_KEYS{ 350 };
static const int NUM_MOUSEBUTTONS{ 8 };

class Input
{
public:
	static auto Update() -> void;

	static auto KeyCallback(GLFWwindow* window, int key, 
							int scancode, int action, 
							int mods) -> void;
	static auto MouseButtonCallback(GLFWwindow* window, 
									int button, int action, 
									int mods) ->void;
	static auto CursorPosCallback(GLFWwindow* window, 
								  double posX, 
								  double posY) -> void;
	static auto CursorScrollCallback(GLFWwindow* window, 
								    double offsetX, 
									double posY) -> void;

	static auto GetKey(int keyCode)		-> bool { return m_keyInputs[keyCode]; }
	static auto GetKeyDown(int keyCode) -> bool { return m_pressKeys[keyCode]; }
	static auto GetKeyUp(int keyCode)   -> bool { return m_releaseKeys[keyCode]; }

	static auto GetMouse(const int button)	   -> bool { return m_mouseInputs[button]; }
	static auto GetMouseDown(const int button) -> bool { return m_pressMouse[button]; }
	static auto GetMouseUp(const int button)   -> bool { return m_releaseMouse[button]; }

	static auto GetCursorPosition() -> const vec2&;
	static auto GetScrollOffset()   -> const vec2& { return m_scrollOffset; }

	static auto SetWindow(GLFWwindow* window)	  -> void { m_window = window; }
	static auto SetCursorVisibility(bool visible) -> void;
	static auto SetCursorPosition(vec2 position)  -> void;

private:
	static vec2 m_mousePos;
	static vec2 m_scrollOffset;
	static GLFWwindow* m_window;

	static bool m_keyInputs[NUM_KEYS];
	static bool m_pressKeys[NUM_KEYS];
	static bool m_releaseKeys[NUM_KEYS];

	static bool m_mouseInputs[NUM_MOUSEBUTTONS];
	static bool m_pressMouse[NUM_MOUSEBUTTONS];
	static bool m_releaseMouse[NUM_MOUSEBUTTONS];
};

#endif