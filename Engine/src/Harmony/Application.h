#pragma once

#include "Base.h"
#include "Window.h"


namespace Harmony {

    class Application
    {
    public:
        Application(/* args */);
        virtual ~Application();

        void Run();
        
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

}
