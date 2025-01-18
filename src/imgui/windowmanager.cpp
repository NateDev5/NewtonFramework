//
// Created by nate on 1/12/25.
//

#include "imgui/windowmanager.h"

void NewtonFramework::WindowManager::displayWindows() {
    for (const auto& [name, window] : windows)
        if (window) window->display();

    while (!closeQueue.empty()) {
        std::string name = closeQueue.front();
        windows.erase(name);
        //
        closeQueue.pop();
    }
}

void NewtonFramework::WindowManager::onWindowClose(ImGuiWindow* window) {
    if (window != nullptr)
        closeQueue.push(window->getWindowName());
}