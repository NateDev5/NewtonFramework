//
// Created by nate on 1/12/25.
//

#include "imguiwindow.h"

#include <imgui.h>

#include "windowmanager.h"

void NewtonFramework::ImGuiWindow::setWindowManager(WindowManager *windowManager_) {
    windowManager = windowManager_;
}

std::string NewtonFramework::ImGuiWindow::getWindowName() {
    return windowName;
}

void NewtonFramework::ImGuiWindow::display() {
    ImGui::Begin(windowName.c_str(), &state);
    if (!state && windowManager != nullptr) {
        windowManager->onWindowClose(this);
        ImGui::End();
        return;
    }
    render();
    ImGui::End();
}

void NewtonFramework::ImGuiWindow::setWindowName(const std::string &windowName_) {
    windowName = windowName_;
}