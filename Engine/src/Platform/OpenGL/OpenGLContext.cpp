#include "OpenGLContext.h"
#include "Harmony/Base.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Harmony {

    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle) {
        HY_CORE_ASSERT(windowHandle, "Window Handle is null");
    }

    void OpenGLContext::Init() {
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        HY_CORE_ASSERT(status, "Failed to initialize Glad!");
        
        HY_CORE_INFO("OpenGL Info:");
        HY_CORE_INFO("Vendor: {0}", (char*) glGetString(GL_VENDOR));
        HY_CORE_INFO("Renderer: {0}", (char*) glGetString(GL_RENDERER));
        HY_CORE_INFO("Version: {0}", (char*) glGetString(GL_VERSION));
    }

    void OpenGLContext::SwapBuffers() {
        glfwSwapBuffers(m_WindowHandle);
    }

}
