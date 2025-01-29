#include "RendererCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Harmony {

    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();

}
