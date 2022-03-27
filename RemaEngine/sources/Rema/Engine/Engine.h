#ifndef REMA_ENGINE_H
#define REMA_ENGINE_H

#include "Core.h"

#include "Rema/Engine/Window.h"

namespace remaEngine
{
	class REMA_API Engine
	{
	public:
		Engine();
		virtual ~Engine();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in client
	Engine* CreateApplication();
}

#endif // !REMA_ENGINE_H

