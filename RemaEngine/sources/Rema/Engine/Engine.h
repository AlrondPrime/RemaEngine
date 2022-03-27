#ifndef REMA_ENGINE_H
#define REMA_ENGINE_H

#include "Rema/Engine/Window.h"
#include "Rema/Input/Action.h"
#include "Rema/Engine/LayerStack.h"
#include "Rema/Input/WindowAction.h"

namespace remaEngine
{
    class REMA_API Engine
    {
    public:
        Engine();
        virtual ~Engine();

        void OnAction(Action& act);
        void Run();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
    private:
        bool OnWindowClosed(WindowCloseAction& action);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

    // To be defined in client
    Engine* CreateApplication();
}

#endif // !REMA_ENGINE_H

