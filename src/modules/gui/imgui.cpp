//
// Created by nate on 1/12/25.
//

#include "imgui.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "core/application.h"

#include "fonts/jetbrains_mono_nerd.h"

void NewtonFramework::MImGui::onAttach() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    auto* win = static_cast<GLFWwindow*>(Application::instance->getWindow().getWindowPtr());
    ImGui_ImplOpenGL3_Init("#version 410");
    ImGui_ImplGlfw_InitForOpenGL(win, true);

    ImGuiIO &io = ImGui::GetIO();
    (void) io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    // load private use area to access some of the icons in the nerd font
    ImWchar ranges[] = { 0x0020, 0xFFFF, 0xE000, 0xF8FF, 0 };

    ImFontConfig fontConfig;
    fontConfig.FontDataOwnedByAtlas = false; // important so that imgui dosent try and fuck with things it dosent own

    // import default from mem
    io.Fonts->AddFontFromMemoryTTF(JetBrainsMonoNerdFont_Bold_ttf, JetBrainsMonoNerdFont_Bold_ttf_len, 18.0f, &fontConfig, ranges);
    io.Fonts->Build();

}

void NewtonFramework::MImGui::onUpdateStart() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::DockSpaceOverViewport(ImGui::GetMainViewport()->ID);
}

void NewtonFramework::MImGui::onUpdate() {
}

void NewtonFramework::MImGui::onUpdateEnd() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void NewtonFramework::MImGui::onDestroy() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
