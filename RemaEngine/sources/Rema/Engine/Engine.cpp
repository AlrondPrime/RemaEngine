#include "remapch.h"
#include "Engine.h"

#include <GLFW/glfw3.h>

namespace remaEngine
{
    #define BIND_ACTION_FUNCTION(x) std::bind(&x, this, std::placeholders::_1)

    Engine::Engine()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetActionCallback(BIND_ACTION_FUNCTION(Engine::OnAction));
    }

    Engine::~Engine()
    {

    }

    void Engine::OnAction(Action& act)
    {
        ActionDispatcher dispatcher(act);
        dispatcher.Dispatch<WindowCloseAction>(BIND_ACTION_FUNCTION(Engine::OnWindowClosed));

        REMA_CORE_TRACE("{0}", act);
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

    bool Engine::OnWindowClosed(WindowCloseAction& action)
    {
        m_Running = false;
        return true;
    }
}