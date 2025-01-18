//
// Created by nate on 1/12/25.
//

#include "core/application.h"

#include <format>
#include <iostream>
#include <memory>

#include "core/desktopwindow.h"
#include "imgui/wlogs.h"
#include "imgui/wprofiler.h"
#include "modules/gui/imgui.h"
#include "modules/time/time.h"
#include "rendering/baserenderer.h"
#include "tools/profiler.h"
#include "utils/logging/logger.h"
#include "utils/logging/loggermacros.h"
#include "utils/logging/stdoutsink.h"

NewtonFramework::Application *NewtonFramework::Application::instance = nullptr;

NewtonFramework::Application::Application(const std::string &name, const Version &version) {
    info = {name, version, getOS()};
    instance = this;

    window = std::move(std::make_unique<DesktopWindow>(info.name));
    pushModule(std::make_shared<MImGui>());
    pushModule(std::make_shared<MTime>());
}

NewtonFramework::Application::~Application() {
    destroy();
}

NewtonFramework::OS NewtonFramework::Application::getOS() {
#if defined(_WIN32)
        return Win32;
#elif defined(_WIN64)
        return Win64;
#elif defined(__APPLE__) || defined(__MACH__)
        return MacOS;
#elif defined(__linux__)
    return Linux;
#elif defined(__unix__)
        return Unix;
#else
        return Other;
#endif
}

NewtonFramework::AppInfo &NewtonFramework::Application::getInfo() {
    return info;
}

void NewtonFramework::Application::init() {
    if (enabledFeatures.contains(Stdout_Sink))
        Logger::instance().addSink(std::make_unique<StdoutSink>());

    // if os is not supported then throw an error
    if (info.os == OS::Other) {
        // throw an error and exit
        NWT_ERR("Not supported", "Application");
        destroy();
        exit(-1);
    }

    Menu devToolsMenu = Menu("Dev tools");
    if (enabledFeatures.contains(Logs)) {
        consoleSink = std::make_shared<ConsoleSink>();
        Logger::instance().addSink(consoleSink);

        devToolsMenu.addItem("Logs", [this]() {
            auto newWin = windowManager.addWindow<WLogs>();
            consoleSink->attachConsole(newWin.second);
        });
    }

    if (enabledFeatures.contains(Profiler))
        devToolsMenu.addItem("Profiler", [this]() {
            windowManager.addWindow<WProfiler>();
        });
    addMenu(devToolsMenu);
}

void NewtonFramework::Application::run() {
    init();
    while (window->running()) {
        window->onUpdateStart();

        moduleStack.updateStartAll();

        menuBar.render();
        windowManager.displayWindows();

        moduleStack.updateAll();
        moduleStack.updateEndAll();

        window->onUpdateEnd();

        BaseRenderer::clear();
    }
}

void NewtonFramework::Application::destroy() {
    moduleStack.destroyAll();
    window->onDestroy();
}

void NewtonFramework::Application::pushModule(const std::shared_ptr<Module> &module) {
    moduleStack.pushModule(module);
}

NewtonFramework::Window &NewtonFramework::Application::getWindow() const {
    return *window;
}

void NewtonFramework::Application::addMenu(const Menu &menu) {
    menuBar.addMenu(menu);
}

void NewtonFramework::Application::enableFeature(AppFeatures feature) {
    enabledFeatures.emplace(feature);
}
