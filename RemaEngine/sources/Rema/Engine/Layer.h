#ifndef REMA_LAYER_H
#define REMA_LAYER_H

#include "Rema/Engine/Core.h"
#include "Rema/Input/Action.h"

namespace remaEngine
{
    class REMA_API Layer
    {
    protected:
        std::string m_DebugName;

    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnAction(Action& action) {}

        inline const std::string& GetName() const { return m_DebugName; }
    };
}

#endif // !REMA_LAYER_H
