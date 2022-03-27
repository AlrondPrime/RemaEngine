#ifndef REMA_MOUSEACTION_H
#define REMA_MOUSEACTION_H

#include "Rema/Input/Action.h"

namespace remaEngine
{
    class REMA_API MouseMovedAction : public Action
    {
    private:
        float m_MouseX, m_MouseY;
    public:
        MouseMovedAction(float x, float y) : m_MouseX(x), m_MouseY(y)
        {
        }

        inline float GetX() const { return m_MouseX; }
        inline float GetY() const { return m_MouseY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedAction: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }

        ACTION_CLASS_TYPE(MouseMoved)
        ACTION_CLASS_CATEGORY(ActionCategoryMouse | ActionCategoryInput)
    };

    class REMA_API MouseScrolledAction : public Action
    {
    private:
        float m_MouseXOffset, m_MouseYOffset;
    public:
        MouseScrolledAction(float xOffset, float yOffset)
             : m_MouseXOffset(xOffset), m_MouseYOffset(yOffset)
        {
        }

        inline float GetXOffset() const { return m_MouseXOffset; }
        inline float GetYOffset() const { return m_MouseYOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledAction: " << m_MouseXOffset << ", " << m_MouseYOffset;
            return ss.str();
        }

        ACTION_CLASS_TYPE(MouseScrolled)
        ACTION_CLASS_CATEGORY(ActionCategoryMouse | ActionCategoryInput)
    };

    class REMA_API MouseButtonAction : public Action
    {
    public:
        inline int GetMouseButton() const { return m_MouseButton; }

        ACTION_CLASS_CATEGORY(ActionCategoryMouse | ActionCategoryInput)
    protected:
        MouseButtonAction(int button) : m_MouseButton(button)
        {
        }

        int m_MouseButton;
    };

    class REMA_API MouseButtonPressedAction : public MouseButtonAction
    {
    public:
        MouseButtonPressedAction(int button) : MouseButtonAction(button)
        {
        }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedAction: " << m_MouseButton;
            return ss.str();
        }

        ACTION_CLASS_TYPE(MouseButtonPressed)
    };

    class REMA_API MouseButtonReleasedAction : public MouseButtonAction
    {
    public:
        MouseButtonReleasedAction(int button) : MouseButtonAction(button)
        {
        }

        std::string ToString() const override 
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedAction: " << m_MouseButton;
            return ss.str();
        }

        ACTION_CLASS_TYPE(MouseButtonReleased)
    };
}

#endif // !REMA_MOUSEACTION_H
