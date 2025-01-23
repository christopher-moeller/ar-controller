#pragma once

#include "Base.h"
#include "Window.h"
#include "Harmony/Events/ApplicationEvent.h"


namespace Harmony {

    class Application
    {
    public:
        Application(/* args */);
        virtual ~Application();

        void Run();
        
    private:
        void OnEvent(Event& e);
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

}
