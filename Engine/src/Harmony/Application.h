#pragma once

#include "Base.h"
#include "Window.h"
#include "Harmony/Events/ApplicationEvent.h"
#include "Harmony/LayerStack.h"
#include "Harmony/ImGui/ImGuiLayer.h"


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
        
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
        static Application* s_Instance;
        ImGuiLayer* m_ImGuiLayer;
    };

}
