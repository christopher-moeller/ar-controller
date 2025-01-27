#pragma once

#include "Harmony/Input.h"

namespace Harmony {

    class MacInput : public Input {
        
    protected:
        virtual bool IsKeyPressedImpl(int keycode) override;
        virtual bool IsMouseButtonPressedImpl(int button) override;
        virtual std::pair<float, float> GetMousePositionImpl() override;
    };

}
