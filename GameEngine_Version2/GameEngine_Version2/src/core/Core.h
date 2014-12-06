#ifndef CORE_CORE_H
#define CORE_CORE_H
#include <string>

class Window;

class Core
{
public:
	Core(Window* window, double frameRate);

	auto Start() -> void;
	auto Stop()  -> void;

	auto SetIsRunning(bool value) -> void { m_isRunning = value; }
	auto ClassName() const	      -> std::string { return m_className; }
private:
	bool m_isRunning;
	double m_frameTime;
	Window* m_window;

	static const std::string m_className;
};

#endif