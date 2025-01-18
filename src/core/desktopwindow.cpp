//
// Created by nate on 1/12/25.
//

#include "desktopwindow.h"

#include <format>
#include <iostream>

#include "utils/logging/logger.h"
#include "utils/logging/loggermacros.h"

#ifdef DEBUG_BUILD
void NewtonFramework::DesktopWindow::glfwErrorCallback(int error, const char *description) {
   NWT_ERR(std::format("{} {}", error, description), "GLFW");
}
#endif

NewtonFramework::DesktopWindow::DesktopWindow(const std::string &winTitle) {
#ifdef DEBUG_BUILD
    glfwSetErrorCallback(glfwErrorCallback);
#endif

    if (!glfwInit()) {
        NWT_ERR("Failed to init glfw", "GLFW");
        return;
    }

    window = glfwCreateWindow(1920, 1080, winTitle.c_str(), nullptr, nullptr);
    if (window == nullptr) {
        NWT_ERR("Failed to create window", "GLFW");
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        NWT_ERR("Failed to init opengl loader", "GLAD");
        glfwTerminate();
        return;
    }

    glfwSwapInterval(1); // vsync

    //glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);
}

bool NewtonFramework::DesktopWindow::running() const {
    return !glfwWindowShouldClose(window);
}

NewtonFramework::WinSize NewtonFramework::DesktopWindow::getSize() {
    WinSize size{};
    glfwGetWindowSize(window, &size.width, &size.height);
    return size;
}


void NewtonFramework::DesktopWindow::handleInput() {

}

void NewtonFramework::DesktopWindow::handleResize() {

}

void NewtonFramework::DesktopWindow::onUpdateStart() {
    glfwPollEvents();
}

void NewtonFramework::DesktopWindow::onUpdateEnd() {
   /* int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(0, 0, 0, 0);*/
    glfwSwapBuffers(window);
}

void NewtonFramework::DesktopWindow::onDestroy() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void* NewtonFramework::DesktopWindow::getWindowPtr() {
    return window;
}



