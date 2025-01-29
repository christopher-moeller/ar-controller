#pragma once

#include "Harmony/Layer.h"

namespace Harmony {

    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() = default;
        
        void OnAttach() override;
        void OnDetach() override;
        virtual void OnImGuiRender() override;
        
        void Begin();
        void End();
        
    private:
        float m_Time = 0.0f;
    };
    

}
