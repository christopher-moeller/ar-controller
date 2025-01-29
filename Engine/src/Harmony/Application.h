#pragma once

#include "Base.h"
#include "Window.h"
#include "Harmony/Events/ApplicationEvent.h"
#include "Harmony/LayerStack.h"
#include "Harmony/ImGui/ImGuiLayer.h"
#include "Harmony/Renderer/Shader.h"
#include "Harmony/Renderer/Buffer.h"


namespace Harmony {

    class Application
    {
    public:
        Application(/* args */);
        virtual ~Application();

        void Run();
        
        void OnEvent(Event& e);
        
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
        
        inline Window& GetWindow() { return *m_Window; }
        
        inline static Application& Get() { return *s_Instance; }
        
        unsigned int m_VertexArray;
        std::unique_ptr<Shader> m_Shader;
        std::unique_ptr<VertexBuffer> m_VertexBuffer;
        std::unique_ptr<IndexBuffer> m_IndexBuffer;
        
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
        static Application* s_Instance;
        ImGuiLayer* m_ImGuiLayer;
    };

}
