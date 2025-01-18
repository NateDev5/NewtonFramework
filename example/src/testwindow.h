//
// Created by nate on 1/18/25.
//

#pragma once
#include "imgui/imguiwindow.h"

class TestWindow final : public NewtonFramework::ImGuiWindow {
public:
    TestWindow();
    void render() override;
};
