#include "Window.h"
#include "Utl.h"
#include "Input.h"

using std::string;

const string Window::m_className{ "Window" };

Window::Window(int width, int height, const std::string& title) 
	: m_closeRequest(false)
	, m_width(width)
	, m_height(height)
	, m_title(title)
	, m_isOK(true)
{
	static const string methodName = "Window";
	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
	{
		m_isOK = false;
		Utl::SendTrace(Utl::WARNING, "Failed to Initialize GLFW", 
					   ClassName(), methodName);
	}
	else
	{
		(SAMPLES > 0) ? glfwWindowHint(GLFW_SAMPLES, SAMPLES)
					  : glfwWindowHint(GLFW_SAMPLES, 0);

		(WINDOW_RESIZABLE) ? glfwWindowHint(GLFW_RESIZABLE, GL_TRUE)
						   : glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		(FULLSCREEN) ? m_window = glfwCreateWindow(width, height, title.c_str(),
												   glfwGetPrimaryMonitor(), nullptr)
					 : m_window = glfwCreateWindow(width, height, title.c_str(),
							        			   nullptr, nullptr);

		if (m_window == nullptr)
		{
			m_isOK = false;
			Utl::SendTrace(Utl::WARNING, "Failed to Initialize Window",
						   ClassName(), methodName);
		}
		else
		{
			glfwMakeContextCurrent(m_window);
			glfwSetKeyCallback(m_window, Input::KeyCallback);
			glfwSetMouseButtonCallback(m_window, Input::MouseButtonCallback);
			glfwSetCursorPosCallback(m_window, Input::CursorPosCallback);
			glfwSetScrollCallback(m_window, Input::CursorScrollCallback);
			Input::SetWindow(m_window);

			//Initialize GLEW
			glewExperimental = GL_TRUE;
			if (glewInit() != GLEW_OK)
			{
				m_isOK = false;
				Utl::SendTrace(Utl::WARNING, "Failed to Initialize GLEW",
							ClassName(), methodName);
			}
		}
	}
}

Window::~Window()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

auto Window::Update() -> void
{
	if (glfwWindowShouldClose(m_window))
	{
		m_closeRequest = true;
	}

	glfwSwapBuffers(m_window);	
}

auto Window::error_callback(int error, const char* description) -> void
{
	fputs(description, stderr);
}
