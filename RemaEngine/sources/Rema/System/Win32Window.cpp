#include "remapch.h"
#include "Win32Window.h"

#include "Rema/Input/MouseAction.h"
#include "Rema/Input/WindowAction.h"
#include "Rema/Input/KeyboardAction.h"

#include <glad/glad.h>

namespace remaEngine
{
    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char* description)
    {
        REMA_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

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

            glfwSetErrorCallback(GLFWErrorCallback);

            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow(static_cast<int>(props.Width), 
            static_cast<int>(props.Height), m_WindowData.Title.c_str(), 
            nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        REMA_CORE_ASSERT(status, "Failed to initialize Glad");
        glfwSetWindowUserPointer(m_Window, &m_WindowData);
        SetVSync(true);

        // Set GLFW callbacks
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            data.Width = width;
            data.Height = height;

            WindowResizeAction action(width, height);
            data.ActionCallback(action);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            WindowCloseAction action;
            data.ActionCallback(action);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int act, int mods)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            switch (act)
            {
                case GLFW_PRESS:
                {
                    KeyPressedAction action(key, 0);
                    data.ActionCallback(action);
                    break;
                }

                case GLFW_RELEASE:
                {
                    KeyReleasedAction action(key);
                    data.ActionCallback(action);
                    break;
                }

                case GLFW_REPEAT:
                {
                    KeyPressedAction action(key, 1);
                    data.ActionCallback(action);
                    break;
                }
            }
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int act, int mods)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            switch (act)
            {
                case GLFW_PRESS:
                {
                    MouseButtonPressedAction action(button);
                    data.ActionCallback(action);
                    break;
                }

                case GLFW_RELEASE:
                {
                    MouseButtonReleasedAction action(button);
                    data.ActionCallback(action);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            MouseScrolledAction action(static_cast<float>(xOffset), static_cast<float>(yOffset));
            data.ActionCallback(action);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            MouseMovedAction action(static_cast<float>(xPos), static_cast<float>(yPos));
            data.ActionCallback(action);
        });
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