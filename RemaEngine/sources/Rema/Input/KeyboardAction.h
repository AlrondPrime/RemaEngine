#ifndef REMA_KEYBOARDACTION_H
#define REMA_KEYBOARDACTION_H

#include "Rema/Input/Action.h"

namespace remaEngine
{
    class REMA_API KeyboardAction : public Action
    {
    public:
        inline int GetKeyCode() const { return m_KeyCode; }

        ACTION_CLASS_CATEGORY(ActionCategoryKeyboard | ActionCategoryInput)
    protected:
        KeyboardAction(int keycode) : m_KeyCode(keycode)
        {
        }

        int m_KeyCode;
    };

    class REMA_API KeyPressedAction : public KeyboardAction
    {
    private:
        int m_RepeatCounter;
    public:
        KeyPressedAction(int keycode, int repeatCount) 
            : KeyboardAction(keycode), m_RepeatCounter(repeatCount)
        {
        }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedAction: " << m_KeyCode << " (" << m_RepeatCounter << " repeats)";
            return ss.str();
        }

        ACTION_CLASS_TYPE(KeyPressed)
    };

    class REMA_API KeyReleasedAction : public KeyboardAction
    {
    public:
        KeyReleasedAction(int keycode) : KeyboardAction(keycode)
        {
        }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedAction: " << m_KeyCode;
            return ss.str();
        }

        ACTION_CLASS_TYPE(KeyReleased)
    };
}

#endif // !REMA_KEYBOARDACTION_H


