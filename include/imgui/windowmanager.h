//
// Created by nate on 1/12/25.
//

#pragma once

#include <memory>
#include <queue>
#include <unordered_map>

#include "imguiwindow.h"

template<typename T>
concept isWindow = std::derived_from<T, NewtonFramework::ImGuiWindow>;
namespace NewtonFramework {
    class WindowManager {
    private:
        std::unordered_map<std::string, std::shared_ptr<ImGuiWindow> > windows;
        std::queue<std::string> closeQueue;

    public:
        template<typename T>
            requires isWindow<T>
        std::pair<std::string, std::shared_ptr<T> > addWindow() {
            std::shared_ptr<T> win = std::make_shared<T>();
            win->setWindowManager(this);
            auto entry = windows.emplace(win->getWindowName(), win);
            return {win->getWindowName(), std::static_pointer_cast<T>(entry.first->second)};
        }

        void displayWindows();

        void onWindowClose(ImGuiWindow *window);
    };
}