#include <iostream>
#include "Harmony.h"


class ExampleLayer : public Harmony::Layer {
public:
    ExampleLayer() : Layer("Example") {
        
    }
    
    void OnUpdate() override {
        HY_INFO("ExampleLayer::Update");
    }
    
    void OnEvent(Harmony::Event& event) override {
        HY_TRACE("{0}", event.ToString());
    }
};


class Sandbox : public Harmony::Application {
    
public:
    Sandbox() {
        PushLayer(new ExampleLayer());
    }
    
};

int main() {
    
    Harmony::Log::Init();
    
    HY_INFO("Test");

    Sandbox* sandbox = new Sandbox();
    sandbox->Run();
    delete sandbox;
}
