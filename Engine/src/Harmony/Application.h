#pragma once

#include "Base.h"
#include "Window.h"
#include "Harmony/Events/ApplicationEvent.h"
#include "Harmony/LayerStack.h"
#include "Harmony/ImGui/ImGuiLayer.h"
#include "Harmony/Renderer/Shader.h"
#include "Harmony/Renderer/Buffer.h"
#include "Harmony/Renderer/VertexArray.h"


namespace Harmony {

    class Application
    {
    public:
        Application(/* args */);
        virtual ~Application() = default;

        void Run();
        
        void OnEvent(Event& e);
        
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
        
        inline Window& GetWindow() { return *m_Window; }
        
        inline static Application& Get() { return *s_Instance; }
        
        std::shared_ptr<Shader> m_Shader;
        std::shared_ptr<VertexArray> m_VertexArray;
        std::shared_ptr<Shader> m_BlueShader;
        std::shared_ptr<VertexArray> m_SquareVA;
        
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
        static Application* s_Instance;
        ImGuiLayer* m_ImGuiLayer;
    };

}
