//
// Created by nate on 1/18/25.
//

#include "testwindow.h"

#include <imgui.h>

#include "events.h"
#include "utils/events/eventbus.h"
#include "global.h"

TestWindow::TestWindow() {
    setWindowName("Test Window");
}

void TestWindow::render() {
    ImGui::Text("This is a test window from NewtonFramework!");
    ImGui::Text("Value : %d", testModule->getValue());

    if (ImGui::Button("Add"))
        NWT_EVENTS.invoke<TestEventAdd>(TestEventAdd());

    if (ImGui::Button("Sub"))
        NWT_EVENTS.invoke<TestEventSub>(TestEventSub());

    ImGui::Text("Delta time : %f", NWT_TIME->deltaTime());
}
