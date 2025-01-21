#include "Application.h"
#include <iostream>
#include "unistd.h"

namespace Harmony {

    Application::Application(/* args */)
    {
        
    }
    
    Application::~Application()
    {
    }

    void Application::Run() {
        while(true) {
            sleep(1);
            std::cout << "Run" << std::endl;
        }
    }
}
