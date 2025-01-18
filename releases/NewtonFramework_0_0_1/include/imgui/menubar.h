//
// Created by nate on 1/12/25.
//

#pragma once
#include <functional>
#include <string>

namespace NewtonFramework {
    class MenuItem {
    private:
        std::string name;
        std::function<void()> action;
    public:
        MenuItem(const std::string &name_, const std::function<void()> &action_);

        void render() const;
    };

    class Menu {
    private:
        std::string name;
        std::vector<MenuItem> items;
    public:
        Menu(std::string name_);
        void render() const;
        void addItem (const std::string &name_, const std::function<void()> &action_);
        operator bool () const;
    };

    class MenuBar {
    private:
        std::vector<Menu> menus;
    public:
        void render ();
        void addMenu (const Menu &menu);
    };
}