//
// Created by nate on 1/16/25.
//

#include "utils/input/input.h"

#include "utils/input/inputcodes.h"
#include "core/application.h"

NewtonFramework::Input &NewtonFramework::Input::instance() {
    static Input instance;
    return instance;
}

bool NewtonFramework::Input::isKeyPressed(int keyCode) {
    return checkKeyState(keyCode, NWT_PRESS, true);
}

bool NewtonFramework::Input::isKeyDown(int keyCode) {
    return checkKeyState(keyCode, NWT_PRESS);
}

bool NewtonFramework::Input::isMouseButtonPressed(int mouseButton) {
    return checkMouseState(mouseButton, NWT_PRESS, true);
}

bool NewtonFramework::Input::isMouseButtonDown(int mouseButton) {
    return checkMouseState(mouseButton, NWT_PRESS);
}

bool NewtonFramework::Input::checkKeyState(int keyCode, int desiredState, bool once) {
#if defined(_WIN32) || defined(_WIN64) || defined(__linux__) || defined(__unix__)
    auto win = static_cast<GLFWwindow*>(Application::instance->getWindow().getWindowPtr());
    int state = glfwGetKey(win, keyCode);
    int lastState = keyStateCache[keyCode];
    keyStateCache[keyCode] = state;

    if (once && lastState == desiredState)
        return false;

    return state == desiredState;
#endif
}

bool NewtonFramework::Input::checkMouseState(int mouseButton, int desiredState, bool once) {
#if defined(_WIN32) || defined(_WIN64) || defined(__linux__) || defined(__unix__)
    auto win = static_cast<GLFWwindow*>(Application::instance->getWindow().getWindowPtr());
    int state = glfwGetMouseButton(win, mouseButton);
    int lastState = mouseStateCache[mouseButton];
    mouseStateCache[mouseButton] = state;

    if (once && lastState == desiredState)
        return false;

    return state == desiredState;
#endif
}

