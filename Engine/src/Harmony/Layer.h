#pragma once

#include "Harmony/Base.h"
#include "Harmony/Events/Event.h"


namespace Harmony {

    class Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& event) {}
        virtual void OnImGuiRender() {}

        inline const std::string& GetName() const { return m_DebugName; }

    protected:
        std::string m_DebugName;
    };

    

}
