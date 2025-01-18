//
// Created by nate on 1/18/25.
//

#include "modules/time/time.h"

#include <GLFW/glfw3.h>

NewtonFramework::MTime *NewtonFramework::MTime::instance = nullptr;

NewtonFramework::MTime::MTime() {
    instance = this;
}

void NewtonFramework::MTime::onAttach() {

}

void NewtonFramework::MTime::onUpdate() {
    auto currentTime = static_cast<float>(glfwGetTime());
    deltaTime_ = currentTime - lastTime_;
    lastTime_ = currentTime;
}

void NewtonFramework::MTime::onUpdateStart() {

}

void NewtonFramework::MTime::onUpdateEnd() {

}

void NewtonFramework::MTime::onDestroy() {

}

float NewtonFramework::MTime::deltaTime() const {
    return deltaTime_;
}




