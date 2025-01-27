#include "MacInput.h"
#include "GLFW/glfw3.h"
#include "Harmony/Application.h"


namespace Harmony {

Input* Input::s_Instance = new MacInput();

    bool MacInput::IsKeyPressedImpl(int keycode) {
        GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool MacInput::IsMouseButtonPressedImpl(int button) {
        GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    std::pair<float, float> MacInput::GetMousePositionImpl() {
        GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        
        return { (float) xpos, (float) ypos };
    }

}
