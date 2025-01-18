//
// Created by nate on 1/13/25.
//

#include "imgui/wprofiler.h"
#include "imgui.h"
#include "tools/profiler.h"

NewtonFramework::WProfiler::WProfiler() {
    setWindowName("Profiler");
}


void NewtonFramework::WProfiler::render() {
    for (const auto& entry : DevTools::Profiler::instance().getData()) {
        ImGui::TextColored(ImVec4(0.8f, 0.5f, 0.09f, 1.0f), "%.2f ms |", entry.second.elapsed);

        ImGui::SameLine();
        ImGui::Text(entry.first.c_str());
    }
}
