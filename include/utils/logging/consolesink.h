//
// Created by nate on 1/12/25.
//

#pragma once
#include <memory>
#include "imgui/wlogs.h"

#include "sink.h"

namespace NewtonFramework {
    class ConsoleSink : public LogSink {
    private:
        std::weak_ptr<WLogs> currentConsole;

        void write(const LogData &logData) override;

    public:
        void attachConsole(const std::weak_ptr<WLogs> &console_);
    };
}
