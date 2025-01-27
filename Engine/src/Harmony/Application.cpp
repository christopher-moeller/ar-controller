#include "Application.h"

#include "Base.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Input.h"

namespace Harmony {

    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        HY_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;
        
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
    }
    
    Application::~Application()
    {
    }

    void Application::PushLayer(Layer *layer) {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *layer) {
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }

    void Application::OnEvent(Event& e) {
        
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
        
        //HY_CORE_TRACE(e.ToString());
        
        for(auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ) {
            (*--it)->OnEvent(e);
            if(e.IsHandled()) {
                break;
            }
        }
    }

    void Application::Run() {
        while(m_Running) {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            
            for(Layer* layer : m_LayerStack) {
                layer->OnUpdate();
            }
            
            m_ImGuiLayer->Begin();
            for (Layer* layer : m_LayerStack)
                layer->OnImGuiRender();
            m_ImGuiLayer->End();
            
            m_Window->OnUpdate();
        }
        
        glfwTerminate();
    }

    bool Application::OnWindowClose(WindowCloseEvent& e) {
        m_Running = false;
        return true;
    }
}
