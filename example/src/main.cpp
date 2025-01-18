//
// Created by nate on 1/18/25.
//

#include <NewtonFramework.h>

#include "testmodule.h"
#include "testwindow.h"
#include "global.h"

int main () {
    auto* app = new NewtonFramework::Application("NewtonFramework Example", {0, 1, 0});

    /**
     * Features
     */
    app->enableFeature(NewtonFramework::Stdout_Sink);
    app->enableFeature(NewtonFramework::Profiler);
    app->enableFeature(NewtonFramework::Logs);

    /*
     * Modules
     */
    app->pushModule(testModule);

    /*
     * Menus
     */
    NewtonFramework::Menu customMenu = NewtonFramework::Menu("Custom menu");
    customMenu.addItem("Test window", [app] () {
        app->addWindow<TestWindow>();
    });
    app->addMenu(customMenu);

    /*
     * Windows
     */
    app->addWindow<TestWindow>();

    app->run();
    delete app;
}
