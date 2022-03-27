#ifndef REMA_ACTION_H
#define REMA_ACTION_H

#include "../Engine/Core.h"

namespace remaEngine
{
	enum class ActionType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum ActionCategory
	{
		None = 0,
		ActionCategoryApplication	= BIT(0),
		ActionCategoryInput			= BIT(1),
		ActionCategoryKeyboard		= BIT(2),
		ActionCategoryMouse			= BIT(3),
		ActionCategoryMouseButton	= BIT(4)
	};

#define ACTION_CLASS_TYPE(type) static ActionType GetStaticType() { return ActionType::##type; }\
								virtual ActionType GetActionType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }
#define ACTION_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class REMA_API Action
	{
		friend class ActionDispatcher;
	public:
		virtual ActionType GetActionType()	const = 0;
		virtual const char* GetName()		const = 0;
		virtual int GetCategoryFlags()		const = 0;
		virtual std::string ToString()		const { return GetName(); }

		inline bool IsInCategory(ActionCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	};

	class ActionDispatcher
	{
		template<typename T>
		using ActionFunction = std::function<bool(T&)>;
	private:
		Action& m_Action;
	public:
		ActionDispatcher(Action& action) : m_Action(action)
		{
		}

		template<typename T>
		bool Dispatch(ActionFunction<T> function)
		{
			if (m_Action.GetActionType() == T::GetStaticType())
			{
				m_Action.m_Handled = function(*(*T) & m_Action);
				return true;
			}
			return false;
		}
	};

	inline std::ostream& operator << (std::ostream& os, const Action& act) 
	{
		return os << act.ToString();
	}
}

#endif // !REMA_ACTION_H
