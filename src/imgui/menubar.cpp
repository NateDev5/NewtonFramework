//
// Created by nate on 1/12/25.
//

#include "imgui/menubar.h"
#include <imgui.h>

NewtonFramework::MenuItem::MenuItem(const std::string &name_, const std::function<void()> &action_) {
    name = name_;
    action = action_;
}

void NewtonFramework::MenuItem::render() const {
    if (ImGui::MenuItem(name.c_str())) action();
}

NewtonFramework::Menu::Menu(std::string name_) {
    name = name_;
}

void NewtonFramework::Menu::addItem(const std::string &name_, const std::function<void()> &action_) {
    items.emplace_back(name_, action_);
}

void NewtonFramework::Menu::render() const {
    if (ImGui::BeginMenu(name.c_str())) {
        for (const MenuItem &menuItem: items)
            menuItem.render();
        ImGui::EndMenu();
    }
}

NewtonFramework::Menu::operator bool() const {
    return !items.empty();
}


void NewtonFramework::MenuBar::addMenu(const Menu &menu) {
    // if menu is not empty
    if (menu) menus.emplace_back(menu);
}

void NewtonFramework::MenuBar::render() {
    if (ImGui::BeginMainMenuBar()) {
        for (const Menu &menu: menus)
            menu.render();
        ImGui::EndMainMenuBar();
    }
}