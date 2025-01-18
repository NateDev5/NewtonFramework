//
// Created by nate on 1/13/25.
//

#pragma once
#include "imguiwindow.h"

namespace NewtonFramework {
    class WProfiler final : public ImGuiWindow {
    public:
        WProfiler();
    protected:
        void render() override;
    };
}

