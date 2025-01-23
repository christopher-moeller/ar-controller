#include "Application.h"

#include "Base.h"
#include "GLFW/glfw3.h"

namespace Harmony {

    Application::Application(/* args */)
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
    }
    
    Application::~Application()
    {
    }

    void Application::OnEvent(Event& e) {
        
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
        
        HY_CORE_TRACE(e.ToString());
    }

    void Application::Run() {
        while(m_Running) {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e) {
        m_Running = false;
        return true;
    }
}
