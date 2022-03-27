#ifndef WINDOW_H
#define WINDOW_H

#include "remapch.h"

#include "Rema/Engine/Core.h"
#include "Rema/Input/Action.h"

namespace remaEngine
{
    struct WindowProps
    {
        std::string Title;

        ruint Width;
        ruint Height;

        WindowProps(const std::string& title = "RemaEngine", ruint width = 1280, ruint height = 720) 
            : Title(title), Width(width), Height(height)
        {
        }
    };

    class REMA_API Window
    {
    public:
        using ActionCallbackFunction = std::function<void(Action&)>;

    public:
        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        virtual ruint GetWidth() const = 0;
        virtual ruint GetHeight() const = 0;

        virtual void SetActionCallback(const ActionCallbackFunction& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& wprops = WindowProps());
    };
}

#endif // !WINDOW_H
