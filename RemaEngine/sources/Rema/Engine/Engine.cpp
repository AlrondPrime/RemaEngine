#include "remapch.h"
#include "Engine.h"

#include <GLFW/glfw3.h>

namespace remaEngine
{
	Engine::Engine()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Engine::~Engine()
	{

	}

	// Runs rema game loop
	void Engine::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}