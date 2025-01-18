//
// Created by nate on 1/12/25.
//

#pragma once
#include <string>

#include "core/window.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace NewtonFramework {
    class DesktopWindow final : public Window {
    private:
        GLFWwindow* window;
#ifdef DEBUG_BUILD
        static void glfwErrorCallback (int error, const char *description);
#endif
    public:
        DesktopWindow(const std::string& winTitle);
        [[nodiscard]] bool running() const override;
        void handleInput() override;
        void handleResize() override;
        WinSize getSize() override;
        void onUpdateStart() override;
        void onUpdateEnd() override;
        void onDestroy() override;
        void *getWindowPtr() override;
    };
}

