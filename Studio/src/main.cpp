#include <iostream>
#include "Harmony.h"


class Sandbox : public Harmony::Application {
    
};

int main() {
    
    Harmony::Log::Init();
    
    HY_INFO("Test");

    Sandbox* sandbox = new Sandbox();
    sandbox->Run();
    delete sandbox;
}
