//
// Created by nate on 1/16/25.
//

#pragma once

#define GLFW_INCLUDE_NONE
#include <unordered_map>
#include <GLFW/glfw3.h>

#define NWT_INPUT NewtonFramework::Input::instance()

namespace NewtonFramework {
    class Input {
    public:
        static Input& instance ();
        bool isKeyPressed (int keyCode);
        bool isKeyDown (int keyCode);
        bool isMouseButtonPressed (int mouseButton);
        bool isMouseButtonDown (int mouseButton);
        float getMouseX ();
        float getMouseY ();
    private:
        bool checkKeyState (int keyCode, int desiredState, bool once = false);
        bool checkMouseState (int mouseButton, int desiredState, bool once = false);
        std::unordered_map<int, int> keyStateCache;
        std::unordered_map<int, int> mouseStateCache;
    };
}