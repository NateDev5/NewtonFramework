//
// Created by nate on 1/12/25.
//

#include "core/modulestack.h"

void NewtonFramework::ModuleStack::pushModule(const std::shared_ptr<Module> &module) {
    // push module on the stack
    modules.push_back(module);
    module->onAttach();
}

void NewtonFramework::ModuleStack::pop() {
    const std::shared_ptr<Module>& lastEl = modules.at(modules.size());
    // call event before destroying
    lastEl->onDestroy();
    // pop from the stack
    modules.pop_back();
}

void NewtonFramework::ModuleStack::updateStartAll() const {
    for (const auto& module: modules)
        module->onUpdateStart();
}

void NewtonFramework::ModuleStack::updateAll() const {
    for (const auto& module: modules)
        module->onUpdate();
}

void NewtonFramework::ModuleStack::updateEndAll() const {
    for (const auto& module: modules)
        module->onUpdateEnd();
}

void NewtonFramework::ModuleStack::destroyAll() {
    for (const auto& module : modules)
        module->onDestroy();

    modules.clear();
}

