#ifndef REMA_WIN32WINDOW_H
#define REMA_WIN32WINDOW_H

#include "Rema/Engine/Window.h"

#include <GLFW/glfw3.h>

namespace remaEngine
{
    class Win32Window : public Window
    {
    private:
        GLFWwindow* m_Window;

        struct WindowData
        {
            std::string Title;

            ruint Width;
            ruint Height;
            bool VSync;

            ActionCallbackFunction ActionCallback;
        };

        WindowData m_WindowData;

        virtual void Init(const WindowProps& props);
        virtual void Shutdown();

    public:
        Win32Window(const WindowProps& props);
        virtual ~Win32Window();

        void OnUpdate() override;

        inline ruint GetWidth() const override { return m_WindowData.Width; }
        inline ruint GetHeight() const override { return m_WindowData.Height; }

        inline void SetActionCallback(const ActionCallbackFunction& callback) override { m_WindowData.ActionCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;
    };
}

#endif // !REMA_WIN32WINDOW_H

