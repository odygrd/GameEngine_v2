#include "Window.h"

#include "Utl.h"

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
	
	(SAMPLES > 0) ? glfwWindowHint(GLFW_SAMPLES, SAMPLES) 
                  : glfwWindowHint(GLFW_SAMPLES, 0);
	(WINDOW_RESIZABLE) ? glfwWindowHint(GLFW_RESIZABLE, GL_TRUE) 
			           : glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	if (FULLSCREEN)
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), 
								    glfwGetPrimaryMonitor(), nullptr);
	}
	else
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), 
									nullptr, nullptr);
	}

	if (!m_window)
	{
		m_isOK = false;
		Utl::SendTrace(Utl::WARNING, "Failed to Initialize Window", 
					   ClassName(), methodName);	
	}

	glfwMakeContextCurrent(m_window);

	glfwSetKeyCallback(m_window, key_callback);

	//Initialize GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		m_isOK = false;
		Utl::SendTrace(Utl::WARNING, "Failed to Initialize GLEW", 
					   ClassName(), methodName);
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
	glfwPollEvents();
	
}
auto Window::error_callback(int error, const char* description) -> void
{
	fputs(description, stderr);
}

auto Window::key_callback(GLFWwindow* window, int key, int scancode, 
					      int action, int mods) -> void
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}