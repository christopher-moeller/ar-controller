#include <iostream>
#include "Harmony.h"
#include "imgui.h"


class ExampleLayer : public Harmony::Layer {
public:
    ExampleLayer() : Layer("Example") {
        
    }
    
    void OnUpdate() override {
        //HY_INFO("ExampleLayer::Update");
        if(Harmony::Input::IsKeyPressed(HY_KEY_TAB)) {
            HY_TRACE("Tab pressed");
        }
    }
    
    void OnEvent(Harmony::Event& event) override {
        //HY_TRACE("{0}", event.ToString());
    }
    
    virtual void OnImGuiRender() override {
        ImGui::Begin("Test");
        ImGui::Text("Hello World");
        ImGui::End();
    }
};


class Sandbox : public Harmony::Application {
    
public:
    Sandbox() {
        PushLayer(new ExampleLayer());
        PushLayer(new Harmony::ImGuiLayer());
    }
    
};

int main() {
    
    Harmony::Log::Init();
    
    HY_INFO("Test");

    Sandbox* sandbox = new Sandbox();
    sandbox->Run();
    delete sandbox;
}
