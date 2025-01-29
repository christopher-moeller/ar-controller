#pragma once

#include "RendererCommand.h"

namespace Harmony {


    class Renderer {

    public:
        
        static void BeginScene();
        static void EndScene();
        
        static void Submit(const std::shared_ptr<VertexArray>& vertextArray);
        
        inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); };
    };

}
