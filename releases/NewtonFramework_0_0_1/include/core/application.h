//
// Created by nate on 1/12/25.
//

#pragma once
#include <optional>
#include <set>
#include <string>

#include "modulestack.h"
#include "type.h"
#include "version.h"
#include "window.h"
#include "imgui/menubar.h"
#include "imgui/windowmanager.h"
#include "utils/logging/consolesink.h"

namespace NewtonFramework {
    struct AppInfo {
        std::string name;
        Version version;
        OS os;
    };

    enum AppFeatures {
        // Adds a profiler window
        Profiler,
        // Adds a custom logs window
        Logs,
        // Write logs to stdout
        Stdout_Sink
    };

    class Application final {
    private:
        std::set<AppFeatures> enabledFeatures;
        ModuleStack moduleStack;
        MenuBar menuBar;
        WindowManager windowManager;

        std::shared_ptr<ConsoleSink> consoleSink;

        OS getOS();

        void init();
        void destroy();
    protected:
        AppInfo info;
        std::shared_ptr<Window> window;
    public:
        static Application* instance;
        Application(const std::string& name, const Version& version);
        ~Application();
        AppInfo &getInfo();
        void run();
        void addMenu (const Menu& menu);
        void enableFeature (AppFeatures feature);
        void pushModule(const std::shared_ptr<Module> &module);
        template<typename T>
        requires isWindow<T>
        void addWindow () {
            windowManager.addWindow<T>();
        }
        [[nodiscard]] Window& getWindow () const;
    };
}

