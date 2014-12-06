#include <iostream>
#include "core\Core.h"
#include "core\Window.h"
#include "core\Utl.h"

using std::cout;
using std::endl;

auto main() -> int
{
	Window window(800, 600, "3D Game Engine");
	Core engine(&window, FRAME_CAP);
	engine.Start();
	return 0;
	//if (window.isOK())
	//{
	//	Utl::SendTrace(Utl::TRACE, "Window Opened Successfully", "Main", "Main");
	//	while (!window.GetCloseRequest())
	//	{
	//		window.Update();
	//	}
	//}
	//
}