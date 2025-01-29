#include "Buffer.h"
#include "Renderer.h"
#include "Harmony/Base.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Harmony {

    VertexBuffer* VertexBuffer::Create(float* vertices, unsigned int size)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:    HY_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::API::OpenGL:  return new OpenGLVertexBuffer(vertices, size);
        }
        HY_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
    IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:    HY_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::API::OpenGL:  return new OpenGLIndexBuffer(indices, size);
        }
        HY_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}
