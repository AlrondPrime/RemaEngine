#include "remapch.h"
#include "Rema/Engine/Layer.h"

namespace remaEngine
{
    Layer::Layer(const std::string& debugName) 
        : m_DebugName(debugName)
    {
    }

    Layer::~Layer()
    {
    }
}