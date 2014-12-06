#include "Core.h"
#include <Windows.h>
#include "Utl.h"
#include "Window.h"
#include "Input.h"

using std::string;

const string Core::m_className{ "Core" };

Core::Core(Window& window, double frameRate)
	: m_isRunning(false)
	, m_frameTime(1.0 / frameRate)
	, m_window(&window)
{
	Utl::SetDeltaTime(m_frameTime);
}

auto Core::Start() -> void
{
	static const string methodName = "Start";
	if (m_isRunning)
	{
		return;
	}

	m_isRunning = true;
	Utl::SendTrace(Utl::TRACE, "OpenGL Version:", ClassName(), methodName);
	Utl::SendTrace(Utl::TRACE, "Renderer:", ClassName(), methodName);

	double lastTime{ glfwGetTime() };
	double unprocessedTime{ 0 };
	double frameCounter{ 0 };
	int frames{ 0 };

	while (m_isRunning)
	{
		bool render{ false };
		double startTime{ glfwGetTime() };
		double passedTime{ startTime - lastTime }; // Compute time difference between current and last frame

		lastTime = startTime;

		unprocessedTime += passedTime;
		frameCounter += passedTime;

		//if 1 second passed print and reset
		if (frameCounter >= 1.0f)
		{
			Utl::SendTrace(Utl::TRACE, "Frames Per Second: " + std::to_string(frames), 
						   ClassName(), methodName);
			frames = 0;
			frameCounter = 0;
		}

		while (unprocessedTime > m_frameTime)
		{
			Input::Update();
			render = true;
			unprocessedTime -= m_frameTime;
		}

		if (render || IGNORE_FRAME_CAP)
		{
			m_window->Update();
			frames++;
		}
		else
		{
			Sleep(1);
		}

		if (m_window->GetCloseRequest())
		{
			Stop();
		}

	}
}

auto Core::Stop() -> void
{
	m_isRunning = false;
}
