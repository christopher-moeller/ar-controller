#pragma once

#include "Harmony/Layer.h"

namespace Harmony {

    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

    private:
        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event& event) override;
        
        float m_Time = 0.0f;
    };
    

}
