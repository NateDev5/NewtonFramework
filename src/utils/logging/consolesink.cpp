//
// Created by nate on 1/12/25.
//

#include "consolesink.h"

void NewtonFramework::ConsoleSink::write(const LogData& logData) {
    if (!currentConsole.expired())
        currentConsole.lock()->addLogEntry(logData);
    else currentConsole.reset();
}

void NewtonFramework::ConsoleSink::attachConsole(const std::weak_ptr<WLogs>& console_) {
    if (currentConsole.expired()) currentConsole.reset();
    currentConsole = console_;
}