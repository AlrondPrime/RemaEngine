#ifndef REMA_LAYERSTACK_H
#define REMA_LAYERSTACK_H

#include "Rema/Engine/Core.h"
#include "Rema/Engine/Layer.h"

namespace remaEngine
{
    class REMA_API LayerStack
    {
    private:
        std::vector<Layer*> m_Layers;
        std::vector<Layer*>::iterator m_LayerInsert;

    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);

        std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer*>::iterator end()   { return m_Layers.end(); }
    };
}

#endif // !REMA_LAYERSTACK_H
