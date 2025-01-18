//
// Created by nate on 1/12/25.
//

#pragma once
#include <string>

namespace NewtonFramework {
    class WindowManager;
    class ImGuiWindow {
    private:
        bool state = true;
        std::string windowName = "Window";
        WindowManager* windowManager = nullptr;
    public:
        virtual ~ImGuiWindow() = default;
        void display ();
        void setWindowName (const std::string &windowName_);
        void setWindowManager(WindowManager* windowManager_);
        std::string getWindowName ();
    protected:
        virtual void render () = 0;
    };
}