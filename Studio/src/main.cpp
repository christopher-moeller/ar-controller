#include <iostream>
#include "Harmony.h"


class Sandbox : public Harmony::Application {
    
};

int main() {
    
    Harmony::Log::Init();
    //Harmony::Log::GetCoreLogger()->warn("Initialized Log!");
    //Harmony::Log::GetClientLogger()->info("Hello");
    HY_CORE_ERROR("This is just a test");
    
    int a = 5;
    HY_INFO("Hello Var={0}", a);

    Sandbox* sandbox = new Sandbox();
    sandbox->Run();
    delete sandbox;
}
