#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <string>

class Window
{
public:
	Window(int width, int height, const std::string& title);
	~Window();

	auto Update() -> void;

	auto ClassName() const	     -> const std::string& { return m_className; }
	auto isOK() const			 -> bool { return m_isOK; }
	auto GetCloseRequest() const -> bool { return m_closeRequest; }
	auto GetWidth() const	     -> int { return m_width; }
	auto GetHeight() const	     -> int { return m_height; }
	auto GetTitle()	const	     -> const std::string& { return m_title; }
	
	static auto error_callback(int error, const char* description) -> void;

private:
	int			m_width;
	int			m_height;
	bool	    m_closeRequest;
	bool		m_isOK;
	std::string m_title;
	GLFWwindow* m_window;

	static const std::string m_className;
};

#endif