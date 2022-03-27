#include "remapch.h"

#include "Win32Window.h"

namespace remaEngine
{
    static bool s_GLFWInitialized = false;

    Window* Window::Create(const WindowProps& props) 
    {
        return new Win32Window(props);
    }

    Win32Window::Win32Window(const WindowProps& props)
    {
        Init(props);
    }

    Win32Window::~Win32Window()
    {
        Shutdown();
    }

    void Win32Window::Init(const WindowProps& props)
    {
        m_WindowData.Title = props.Title;
        m_WindowData.Width = props.Width;
        m_WindowData.Height = props.Height;

        REMA_CORE_INFO("Creating window \"{0}\" ({1} x {2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized) {
            int succes = glfwInit();
            REMA_CORE_ASSERT(succes, "Could not initialize GLFW");

            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow(static_cast<int>(props.Width), 
            static_cast<int>(props.Height), m_WindowData.Title.c_str(), 
            nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_WindowData);
        SetVSync(true);
    }

    void Win32Window::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void Win32Window::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void Win32Window::SetVSync(bool enabled)
    {
        if (enabled) {
            glfwSwapInterval(1);
        }
        else {
            glfwSwapInterval(0);
        }

        m_WindowData.VSync = enabled;
    }

    bool Win32Window::IsVSync() const
    {
        return m_WindowData.VSync;
    }

}