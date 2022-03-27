#ifndef REMA_WINDOWACTION_H
#define REMA_WINDOWACTION_H

#include "Action.h"

namespace remaEngine
{
	class REMA_API WindowResizeAction : public Action
	{
	private:
		ruint m_WindowWidth, m_WindowHeight;
	public:
		WindowResizeAction(ruint width, ruint height)
			: m_WindowWidth(width), m_WindowHeight(height)
		{
		}

		inline ruint GetWidth() const { return m_WindowWidth; }
		inline ruint GetHeight() const { return m_WindowHeight; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeAction: " << m_WindowWidth << ", " << m_WindowHeight;
			return ss.str();
		}

		ACTION_CLASS_TYPE(WindowResize)
		ACTION_CLASS_CATEGORY(ActionCategoryApplication)
	};

	class REMA_API WindowCloseAction : public Action
	{
	public:
		WindowCloseAction() {}

		ACTION_CLASS_TYPE(WindowClose)
		ACTION_CLASS_CATEGORY(ActionCategoryApplication)
	};

	class REMA_API AppTickAction : public Action
	{
	public:
		AppTickAction() {}

		ACTION_CLASS_TYPE(AppTick)
		ACTION_CLASS_CATEGORY(ActionCategoryApplication)
	};

	class REMA_API AppUpdateAction : public Action
	{
	public:
		AppUpdateAction() {}

		ACTION_CLASS_TYPE(AppUpdate)
		ACTION_CLASS_CATEGORY(ActionCategoryApplication)
	};

	class REMA_API AppRenderAction : public Action
	{
	public:
		AppRenderAction() {}

		ACTION_CLASS_TYPE(AppRender)
		ACTION_CLASS_CATEGORY(ActionCategoryApplication)
	};
}

#endif // !REMA_WINDOWACTION_H
